#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2e5+7,mod=1e9+7,mod2=mod*mod;typedef ll aN[N];aN a;std::bitset<289>f;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='0',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int main(){
    ll w=readll(),ans=0,s;rep(i,1,8){a[i]=readll();if(a[i]*i>w)a[i]=w/i;s=std::max(a[i]-7,0ll),ans+=i*s,w-=i*s,a[i]-=s;}
    w=std::min(w,288ll);f[0]=1;rep(i,1,8)rep(j,1,a[i])f|=f<<i;per(i,w,0)if(f[i]==1)return printf("%lld\n",ans+i),0; 
}