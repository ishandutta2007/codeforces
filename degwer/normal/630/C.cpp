#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    printf("%I64d\n",(1LL<<n)*2-2);
}