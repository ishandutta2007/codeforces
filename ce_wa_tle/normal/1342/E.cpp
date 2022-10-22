#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define rd readll()
typedef long long ll;const ll N=716333,inf=1e17,mod=998244353;typedef ll aN[N];aN jc,njc,ny;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll pow(ll a,ll b,ll p){ll ans=1;while(b){if(b&1)ans=ans*a%p;a=a*a%p,b>>=1;}return ans;}
ll C(ll n,ll m){return n<0||n>m?0:jc[m]*njc[n]%mod*njc[m-n]%mod;}
int main(){
    ll n=readll(),c=n-readll(),ans=0;jc[0]=njc[0]=jc[1]=njc[1]=ny[1]=1;
    rep(i,2,n)jc[i]=jc[i-1]*i%mod,njc[i]=njc[i-1]*(ny[i]=(mod-mod/i)*ny[mod%i]%mod)%mod;//,
//    printf("%lld %lld %lld %lld\n",i,ny[i],jc[i],njc[i]*jc[i]%mod);
    rep(i,0,c)ans=(ans+((c^i)&1?mod-1:1)*C(i,c)%mod*pow(i,n,mod))%mod;ans=ans*C(c,n)%mod;
    printf("%lld\n",(ans+ans*(c!=n))%mod);
}