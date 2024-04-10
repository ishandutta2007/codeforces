#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=2e6+5,mod=998244353,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];
ll readll(){//,printf("%lld %lld %lld\n",k,j,k&~(~j&w));ref(k,0,4)printf("f[%lld][%lld]=%lld\n",i,k,f[k]);
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll solve(ll r0,ll r1){if(r0<0||r1<0)return 0;ll l[4]={0,0,0,0},f[4]={1,1,1,1};rep(i,0,46){ref(k,0,4)l[k]=f[k],f[k]=0;
    ll w=(r1>>i&1)<<1|(r0>>i&1);ref(j,0,3)ref(k,0,4)if(!((j&~w)&k))f[k]=f[k]+l[k&~(~j&w)];}return f[3];
}ll calc(int cases){ll l=readll(),r=readll();return solve(r,r)-solve(l-1,r)*2+solve(l-1,l-1);(void)cases;}
int main(){ll T=readll(),cnt=0;while(T --> 0)printf("%lld\n",calc(++cnt));return 0;}