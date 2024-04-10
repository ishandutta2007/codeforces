#include<stdio.h>
long long n,m,T;
main(){
    scanf("%I64d%I64d%I64d",&n,&m,&T);
    printf("%I64d\n",((n+T-1)/T)*((m+T-1)/T));
}