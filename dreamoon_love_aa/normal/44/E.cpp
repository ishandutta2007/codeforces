#include<stdio.h>
#include<string.h>
main(){
    char s[1024];
    int k,a,b,len,now=0,i,j;
    scanf("%d%d%d%s",&k,&a,&b,s);
    len=strlen(s);
    if(k*a>len||k*b<len)puts("No solution");
    else{
        for(i=0;i<k;i++){
            if(i<len%k)j=len/k+1;
            else j=len/k;
            while(j--)putchar(s[now++]);
            puts("");
        }
    }
}