#include <bits/stdc++.h>

using namespace std;

const long long nmax=1000000;
const long long mod=1000000007;

long long a,b,n,fact[nmax+5];

bool bun(long long val)
{
    while(val>0)
    {
        long long x=val%10;
        if(x!=a && x!=b)
            return 0;
        val/=10;
    }
    return 1;
}
long long expow(long long a,long long b)
{
    long long ans=1;
    while(b)
    {
        if(b%2)
            ans=1ll*ans*a%mod;
        a=1ll*a*a%mod;
        b/=2;
    }
    return ans;
}
void build_fact()
{
    fact[0]=1;
    for(int i=1;i<=nmax;i++)
        fact[i]=1ll*fact[i-1]*i%mod;
}
long long comb(long long a,long long b)
{
    long long x,y;
    x=fact[a];
    y=1ll*fact[b]*fact[a-b]%mod;
    y=expow(y,mod-2);
    return 1ll*x*y%mod;
}
long long total=0;
int main()
{
    build_fact();
    cin>>a>>b>>n;
    for(int x=0;x<=n;x++)
    {
        int y=n-x;
        int val=x*a+y*b;
        if(bun(val))
        {
            total+=comb(n,x);
            total%=mod;
        }
    }
    cout<<total;
    return 0;
}
/**
x de a si y de b

**/