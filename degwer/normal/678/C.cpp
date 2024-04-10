#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
    for(;;)
    {
        if(a>b)swap(a,b);
        b%=a;
        if(b==0)return a;
    }
}
int main()
{
    ll n,a,b,p,q;
    scanf("%I64d%I64d%I64d%I64d%I64d",&n,&a,&b,&p,&q);
    ll g=gcd(a,b);
    printf("%I64d\n",p*(n/a-n/(a*b/g))+q*(n/b-n/(a*b/g))+max(p,q)*(n/(a*b/g)));
}