#include<stdio.h>
typedef long long ll;
int main()
{
    ll n;
    scanf("%I64d",&n);
    ll a=(n+4)*(n+3)*(n+2)*(n+1)*n/120;
    ll b=(n+2)*(n+1)*n/6;
    printf("%I64d\n",a*b);
}