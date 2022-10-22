#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=300005;
ll dp[N][3];
int n,m;
ll a[N];
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	memset(dp,0x80,sizeof(dp));
	dp[0][0]=0;
	ll ans=0;
	for(i=1;i<=n;i++){
		dp[i][0]=max(dp[i-1][0]+a[i],0ll);
		dp[i][1]=max(max(dp[i-1][0],dp[i-1][1])+a[i]*m,0ll);
		dp[i][2]=max(max(dp[i-1][1],dp[i-1][2])+a[i],0ll);
		ans=max(ans,dp[i][0]);
		ans=max(ans,dp[i][1]);
		ans=max(ans,dp[i][2]);
	}
	cout<<ans;
	return 0;
}