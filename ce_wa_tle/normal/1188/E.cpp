#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define mem(x,y) memset(x,y,sizeof(x))
typedef long long ll;const ll N=4222222,mod=998244353;typedef ll aN[N]; 
void qmin(ll&a,ll b){if(a>b)a=b;}
inline ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}inline int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
aN p,a,ny,jc,njc;inline ll C(ll n,ll m){return jc[m]*njc[n]%mod*njc[m-n]%mod;}
int main(){
    ll n=readll(),m=0,sr=0;rep(i,1,n)m=std::max(m,a[i]=readll());sr=n+m;
    rep(i,1,n)rfor(ll j=a[i]+1;j<=sr;j+=n)p[j]++;rep(i,1,sr)if((p[i]+=p[i-1])>i)sr=i-1;
    ny[1]=jc[1]=njc[1]=jc[0]=njc[0]=1;
    rep(i,2,sr+n)jc[i]=jc[i-1]*i%mod,njc[i]=njc[i-1]*(ny[i]=(mod-mod/i)*ny[mod%i]%mod)%mod;
    ll sum=0;rep(i,std::max(0ll,sr-n+1),sr)sum+=C(i-p[i],i-p[i]+n-1);printf("%lld\n",sum%mod);return 0;
}