#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int T,ans;
long long b,q,y,c,r,z;
inline void solve(long long p)
{
    if(p*q==r*__gcd(p,q))
        ans=(ans+r/p*(r/p))%mod;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld %lld %lld",&b,&q,&y);
        scanf("%lld %lld %lld",&c,&r,&z);
        if(r%q || c<b || c+(z-1)*r>b+(y-1)*q || (c-b)%q)
            {puts("0");continue;}
        if((c-r)<b || c+z*r>b+(y-1)*q)
            {puts("-1");continue;}
        ans=0;
        for(int i=1;i*i<=r;++i)
            if(!(r%i))
            {
                solve(i);
                if(i*i!=r) solve(r/i);
            }
        printf("%d\n",ans);
    }
    return 0;
}