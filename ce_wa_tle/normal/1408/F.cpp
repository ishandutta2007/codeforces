#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i++)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=6e5+9,inf=1e9,mod=1e9+7;typedef ll aN[N];aN a;
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int main(){
    ll n=readll();ll s=1,w=0;while(s*2<=n)s*=2,w++;printf("%lld\n",s*w);
    rfor(ll w=1;s>>w;w++)ref(i,0,s>>w)ref(j,0,1<<(w-1))printf("%lld %lld\n",(i<<w|j)+1,(i<<w|j|1<<(w-1))+1);
    rfor(ll w=1;s>>w;w++)ref(i,0,s>>w)ref(j,0,1<<(w-1))printf("%lld %lld\n",n-(i<<w|j),n-(i<<w|j|1<<(w-1)));return 0;
}