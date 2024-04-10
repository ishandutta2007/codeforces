#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=(ll)1e9+7;
const int N=2505;
const int M=100005;
ll qpow(ll x,ll y)
{
    ll ret=1;
    while(y)
    {
        if(y&1) ret=ret*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return ret;
}

int n,a[N];
ll f[M],sum;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
    f[1]=(sum-1)*(sum-1)%MOD*qpow(sum,MOD-2)%MOD;
    for(int i=1;i<100000;i++)
    {
        f[i+1]=((2ll*f[i]-f[i-1]+MOD)%MOD-(sum-1)*qpow(sum-i,MOD-2)%MOD+MOD)%MOD;
    }
    ll ans=0;
    for(int i=1;i<=n;i++) ans=(ans+f[a[i]])%MOD;
    cout<<ans<<endl;
    return 0;
}