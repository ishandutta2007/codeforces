#include<stdio.h>
main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)putchar('a'+i%4);
    puts("");
}