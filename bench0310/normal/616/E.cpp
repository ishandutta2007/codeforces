#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,m;
    scanf("%I64d%I64d",&n,&m);
    const long long mod=1000000007;
    long long res=0;
    if(n<m)
    {
        res=(((m-n)%mod)*(n%mod))%mod;
        m=n;
    }
    long long idx=m;
    while(idx>0)
    {
        long long l=0,r=idx;
        while(l<r-1)
        {
            long long mid=(l+r)/2;
            if((n/mid)==(n/idx)) r=mid;
            else l=mid;
        }
        long long num=(idx-r+1)%mod;
        long long a=(n%idx)%mod;
        long long d=(n/idx)%mod;
        long long x=d;
        x=(x*num)%mod;
        x=(x*(num-1))%mod;
        x=(x*500000004)%mod;
        x=(x+a*num)%mod;
        res=(res+x)%mod;
        idx=r-1;
    }
    printf("%I64d\n",res);
    return 0;
}