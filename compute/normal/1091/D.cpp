#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
const int mod=998244353;
long long fac[maxn];
void db()
{
    fac[0]=1;
    for(int i=1;i<maxn;i++)
    {
        fac[i]=fac[i-1]*i%mod;
    }
}
int main()
{
    db();
    int n;
    scanf("%d",&n);
    long long ans=1;
    for(int i=2;i<=n;i++)
    {
        ans=(ans+fac[i-1]-1+mod)%mod;
        ans=ans*i%mod;
    }
    printf("%lld\n",ans);
}