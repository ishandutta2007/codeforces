#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2e5+7,inf=998244353;typedef ll aN[N];aN a,b,c;ll ans=0;
ll readll(){
    ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
    for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){if(l>r)std::swap(l,r);int c=getchar();for(;c<l||c>r;c=getchar());return c;}
struct hs{const ll mod,k;aN w,pre,suc;hs(ll mod_,ll k_):mod(mod_),k(k_){}
void calc(ll n,ll*b){
    w[0]=1;rep(i,1,n)w[i]=w[i-1]*k%mod,pre[i]=(pre[i-1]*k+b[i])%mod;per(i,n,1)suc[i]=(suc[i+1]*k+b[i])%mod;
}int check(ll l,ll r){return(pre[r]+(mod-pre[l-1])*w[r-l+1])%mod==(suc[l]+(mod-suc[r+1])*w[r-l+1])%mod;}
}t1(1e9+7,220),t2(1e9+9,333);
int main(){
    ll n=readll(),m=readll();rep(i,1,n)a[i]=readll();std::sort(a+1,a+n+1);
    rep(i,1,n)b[i]=a[i+1]-a[i];t1.calc(n,b),t2.calc(n,b);rep(i,1,n)
    if((i==n||(a[i+1]+a[n]-m==a[1]+a[i]&&t1.check(i+1,n-1)&&t2.check(i+1,n-1)))&&t1.check(1,i-1)&&t2.check(1,i-1))
    c[++ans]=(a[1]+a[i])%m;printf("%lld\n",ans);std::sort(c+1,c+ans+1);rep(i,1,ans)printf("%lld ",c[i]);return 0;
}