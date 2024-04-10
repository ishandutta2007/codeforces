#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6; const ll INF=1e18; 
ll dp[N]; ll r1,r2,r3,d,a[N];
ll kill(int i,int t,int b){
	ll x=min((a[i]+2)*r1+t*d,r1+r2+t*d);
	if (b) x=min(x,a[i]*r1+r3);
	return x;
}
int main(){
	int n; scanf("%d%lld%lld%lld%lld",&n,&r1,&r2,&r3,&d);
	rep(i,1,n) scanf("%lld",&a[i]);
	dp[0]=0;
	rep(i,1,n){
		dp[i]=dp[i-1]+kill(i,2,1);
		if (i>=2){
			dp[i]=min(dp[i],dp[i-2]+2*d+2*(r1+r2));
			dp[i]=min(dp[i],dp[i-2]+2*d+(a[i]+a[i-1]+4)*r1);
		}
	}
	ll ans=dp[n],s=0;
	rep(i,2,n)
		s+=kill(n-i+1,1,0),ans=min(ans,dp[n-i]+kill(n,2,1)+s);
	printf("%lld\n",ans+(n-1)*d);
	return 0;
}