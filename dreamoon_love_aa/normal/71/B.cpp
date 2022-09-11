#include<stdio.h>
main(){
    int n,k,t,r,i;
    scanf("%d%d%d",&n,&k,&t);
    r=n*k*t/100;
    for(i=0;i<n;i++){
        if(i)putchar(' ');
        printf("%d",k<r?k:r);
        r-=k;
        if(r<0)r=0;
    }
    puts("");
}