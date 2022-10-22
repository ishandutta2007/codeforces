#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i++)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=1e5+5,inf=1e18;typedef ll aN[N];ll s[N][17],dp[N][228],a[N],c[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
ll cmp(ll x,ll y){return a[x]>a[y];}
int main(){
	ll n=readll(),p=readll(),k=readll(),z=(1<<p)-1;rep(i,1,n)a[c[i]=i]=readll();
	rep(i,1,n)ref(j,0,p)s[i][j]=readll();std::sort(c+1,c+n+1,cmp);rep(i,1,z)dp[0][i]=-inf;
	rep(i,1,n)rep(S,0,z){
		dp[i][S]=-inf;
		ll cnt=0;ref(j,0,p)if(S>>j&1)dp[i][S]=std::max(dp[i][S],dp[i-1][S^1<<j]+s[c[i]][j]),++cnt;
//		printf("dp[%lld][%lld]=%lld\n",i,S,dp[i][S]);
		dp[i][S]=std::max(dp[i][S],i-cnt>k?dp[i-1][S]:dp[i-1][S]+a[c[i]]);
//		printf("dp[%lld][%lld]=%lld %lld\n",i,S,dp[i][S],dp[0][2]);
	}printf("%lld\n",dp[n][z]);return 0;
}