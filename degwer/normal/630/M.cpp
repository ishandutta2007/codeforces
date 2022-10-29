#include<stdio.h>
typedef long long ll;
int main()
{
    ll t;
    scanf("%I64d",&t);
    t+=1800000000000000000LL;
    t%=360;
    if(t<=45)printf("0\n");
    else if(t<=135)printf("1\n");
    else if(t<=225)printf("2\n");
    else if(t<315)printf("3\n");
    else printf("0\n");
}