#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define dprintf(x...) fprintf(stderr,x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=5e5+7;typedef ll aN[N],a2N[2*N],a40N[40*N];
ll readll(){
    ll x=0,w=1;char c=getchar();
    for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());
    return x*w;
}
const ll mod=998244353;
ll pow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod,b>>=1;
    }
    return ans;
}
ll sf[23],*f=sf,g[1700000];
int main(){
    //IO(P4770);
    ll n=readll()/2,k=readll();rep(i,1,k)f[readll()]++;
    //g=f^k
    //g'=kf'f^{k-1}
    //g'f=kf'g
    //\sum_{i=0}^10f_i(n-i+1)g_{n-i+1}=\sum_{i=0}^10k(i+1)f_{i+1}g_{n-i}
    while(!*f)f++;g[0]=pow(f[0],n);ll ans=g[0]*g[0]%mod;
    ref(i,0,n*10){
        ll a=0,b=(i+1)*f[0]%mod;
        rep(j,0,std::min(10ll,i+0))a=(a+n*(j+1)%mod*f[j+1]%mod*g[i-j])%mod;
        rep(j,1,std::min(10ll,i+1))a=(a+(mod-f[j])*(i-j+1)%mod*g[i-j+1])%mod;//,
//        printf("s%lld\n",a);
        g[i+1]=a*pow(b,mod-2)%mod,ans=(ans+g[i+1]*g[i+1])%mod;
//        if(i<=500*7)printf("%lld\n",g[i]);
    }
    printf("%lld\n",ans);
    return 0;
}