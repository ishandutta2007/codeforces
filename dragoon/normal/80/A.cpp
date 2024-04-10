#include<stdio.h>

int isprime(int x)
{
    if(x==1) return 0;

    int i;
    for(i=2;i<x;i++)
        if(x%i==0)
            return 0;
    return 1;
}

int main()
{
    int n,m,i;

    scanf("%d%d",&n,&m);

    for(i=n+1;;i++)
        if( isprime(i) )
            break;

    if( isprime(n) && i==m )
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}