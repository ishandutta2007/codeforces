#include<stdio.h>
main(){
    int n;
    scanf("%d",&n);
    if(n<=10||n>21)puts("0");
    else{
        if(n<20||n==21)puts("4");
        else puts("15");
    }
}