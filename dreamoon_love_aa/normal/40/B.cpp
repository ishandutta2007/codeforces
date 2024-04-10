#include<stdio.h>
main(){
    int n,m,x;
    scanf("%d%d%d",&n,&m,&x);
    n-=(x-1)<<1;
    m-=(x-1)<<1;
    if(n<=0||m<=0)puts("0");
    else if(n==1)printf("%d\n",(m+1)/2);
    else if(m==1)printf("%d\n",(n+1)/2);
    else printf("%d\n",(n+m)-2);
}