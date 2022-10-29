#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    ll xa,ya,xb,yb;
    scanf("%I64d%I64d%I64d%I64d",&xa,&ya,&xb,&yb);
    if(xa>xb)abort();
    if(ya>yb)abort();
    if(-1000000000>xa)abort();
    if(1000000000<xb)abort();
    if(-1000000000>ya)abort();
    if(1000000000<yb)abort();
    xa+=1000000000;
    ya+=1000000000;
    xb+=1000000000;
    yb+=1000000000;
    ll t=(xb-xa+1)*(yb-ya+1);
    t++;
    printf("%I64d\n",t/2);
}