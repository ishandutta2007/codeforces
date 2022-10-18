#include<bits/stdc++.h>

using namespace std;

const int maxn=300005;

int n;
long long a[maxn] ;
long long x,dp[maxn][3];

int main(){
	cin>>n>>x;
	for(int i=1;i<=n;i++)cin>>a[i];
	long long ans=0;
	for(int i=1;i<=n;i++){
		dp[i][0]=max(dp[i-1][0]+a[i],0ll);
		dp[i][1]=max(max(dp[i-1][0],dp[i-1][1])+a[i]*x,0ll);
		dp[i][2]=max(max(dp[i-1][1],dp[i-1][2])+a[i],0ll);
		ans=max(ans,dp[i][0]);
		ans=max(ans,dp[i][1]);
		ans=max(ans,dp[i][2]);
	}
	cout<<ans;//orzlim
	return 0;
}