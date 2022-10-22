#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;typedef long double ld;const ll N=111,mod=998244353,inf=0x3f3f3f3f3f3f3f3f;ld f[N],g[N];ll to[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int main(){
    ll x;ld now=0;ref(i,0,10)ref(j,0,10)x=i-readll(),to[i*10+(i&1?9-j:j)]=x*10+(x&1?9-j:j);
    ref(i,0,100)f[i]=i==0?0:i<6?6:now/6+1,now+=(g[i]=std::min(f[i],f[to[i]]))-(i>=6?g[i-6]:0);
    printf("%.10lf\n",(double)f[99]);return 0;
}