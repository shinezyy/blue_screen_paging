#include "string.h"
#include "x86.h"
#include "serial.h"
#include "stdio.h"
#include "memlayout.h"

#define VGA_MEM (0xa0000+KERNBASE)
#define blue 1

uint8_t vmbuf[320*200];

void mem_test(){
    int* addr = (int *)(VGA_MEM+100);
    while(addr){
        *addr = 0xc5c5c5c5;
        printk("addr: 0x%x, value: %d\n", addr, *addr);
        addr -= 0x100;
    }
}

void blue_screen(){
	memset(vmbuf, blue, 320*200);
    printk("vmbuf add: 0x%x, VM addr: 0x%x\n", &vmbuf,VGA_MEM);
	memmove((void *) VGA_MEM, vmbuf, 320*200);
}

int main(){
    init_serial();
    printk("fuck\n");
    //mem_test();
	blue_screen();
	hlt();
	return 0;
}
