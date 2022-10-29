#include<stdio.h>
typedef long long ll;
int main()
{
    ll n;
    scanf("%I64d",&n);
    ll a=n*(n-1)*(n-2)*(n-3)*(n-4)/120;
    printf("%I64d\n",a*a*120);
}