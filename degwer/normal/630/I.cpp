#include<stdio.h>
typedef long long ll;
int main()
{
    ll a;
    scanf("%I64d",&a);
    printf("%I64d\n",(1LL<<(2*(a-3)))*4*3*2+(1LL<<(2*(a-4)))*4*3*3*(a-3));
}