#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=1e6+7,mod=998244353,inf=1e18;typedef ll aN[N];aN a,b,jc,njc,ny;ll qC[5555][5555];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int main(){
    const ll n=readll();ll m=0,lst=0;rep(i,1,n)a[i]=readll();std::sort(a+1,a+n+1);jc[0]=jc[1]=njc[0]=njc[1]=ny[1]=1;
    rep(i,2,n)jc[i]=jc[i-1]*i%mod,njc[i]=njc[i-1]*(ny[i]=(mod-mod/i)*ny[mod%i]%mod)%mod;qC[0][0]=1;
    rep(i,1,n)if(a[i]!=a[i+1])lst+=b[++m]=i-lst;rep(i,1,m)rep(j,0,i)qC[i][j]=(qC[i-1][j]+(j?b[i]*qC[i-1][j-1]:0))%mod;
    ll sum=0;rep(i,1,m)if(b[i]>=2)rep(j,0,i-1)sum=(sum+qC[i-1][j]*b[i]%mod*(b[i]-1)%mod*jc[n-2-j])%mod;
    printf("%lld\n",sum*njc[n]%mod);return 0; 
}