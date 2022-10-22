#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
#define INF 9000000000000000007ll
using namespace __gnu_pbds;
using namespace std;

int n,r1,r2,r3,d,a[2000010],val1[2000010],val2[2000010],dp[2000010];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>r1>>r2>>r3>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		val1[i]=r1*a[i]+r3;
		val2[i]=min(r1+r2,r1*(a[i]+2ll));
	}
	dp[0]=0ll;
	for(int i=1;i<=n;i++){
		dp[i]=INF;
		dp[i]=min(dp[i],dp[i-1]+val1[i]);
		dp[i]=min(dp[i],dp[i-1]+val2[i]+2*d);
		if(i>1) dp[i]=min(dp[i],dp[i-2]+val2[i]+val2[i-1]+2*d);
	}
	int sum=0ll;
	for(int i=n-1;i>=1;i--){
		sum+=val2[i];
		dp[n]=min(dp[n],min(val1[n],val2[n]+2*d)+dp[i-1]+(n-i)*d+sum);
	}
	int ans=dp[n]+(n-1)*d;
	cout<<ans<<endl;
	return 0;
}