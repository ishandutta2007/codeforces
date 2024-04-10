#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
using namespace std;
const int N=1e6+6; int a[N],v[N],dp[N]; char s[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,k; scanf("%d%d%s",&n,&k,s); int ans=n;
		rep(i,1,n) a[i]=s[i-1]-'0',v[i]=v[i-1]+a[i];
		if (!v[n]){ puts("0"); continue; }
		rep(i,1,n)
			if (a[i]){
				dp[i]=v[i-1];
				if (i>=k) dp[i]=min(dp[i],dp[i-k]+v[i-1]-v[i-k]);
				ans=min(ans,dp[i]+v[n]-v[i]);
			}
			else{
				dp[i]=v[i];
				if (i>=k) dp[i]=min(dp[i],dp[i-k]+v[i-1]-v[i-k]+1);
			}
		printf("%d\n",ans);
	}
	return 0;
}