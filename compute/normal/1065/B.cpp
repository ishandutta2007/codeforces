#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;
    scanf("%lld%lld",&n,&m);
    long long mi,ma=0;
    mi=n-2*m;
    if(mi<0) mi=0;
    for(long long i=0;i<=n;i++)
    {
        if(i*(i-1)/2>=m)
        {
            ma=i;
            break;
        }
    }
    ma=n-ma;
    printf("%lld %lld\n",mi,ma);
}