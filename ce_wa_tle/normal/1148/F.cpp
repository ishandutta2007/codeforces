#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=1.5e6+7,mod=1e9+7,mod2=mod*mod,inf=1e18;typedef ll aN[N];aN a,b;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int main(){
    const ll n=readll();ll sum=0,ans=0;rep(i,1,n)sum+=a[i]=readll(),b[i]=readll();if(sum<0)rep(i,1,n)a[i]=-a[i];
    rep(i,0,62){ll s=0;rep(j,1,n)if((b[j]>>i)==1)s+=a[j];if(s>0){ans|=1ll<<i;rep(j,1,n)if(b[j]>>i&1)a[j]=-a[j];}}
    printf("%lld\n",ans);return 0;
}