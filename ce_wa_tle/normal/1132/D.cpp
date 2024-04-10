#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2e5+7,mod=1e9+7,mod2=mod*mod;typedef ll aN[N];aN a,b,p;ll n,k;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int check(ll mid){
    ll cnt=0;memset(p,0,sizeof(ll)*(k+1));
    rep(i,1,n){ll now=a[i];while(now<k*b[i]){if(++cnt>k)return 0;p[now/b[i]+1]++,now+=mid;}}
    rep(i,1,k)if((p[i]+=p[i-1])>i)return 0;return 1;
}int main(){
    n=readll(),k=readll()-1;rep(i,1,n)a[i]=readll();rep(i,1,n)b[i]=readll();ll l=0,r=2e12,ans=-1;//check(5);return 0;
    while(l<=r){ll mid=(l+r)>>1;if(check(mid))r=mid-1,ans=mid;else l=mid+1;}printf("%lld\n",ans);return 0; 
}