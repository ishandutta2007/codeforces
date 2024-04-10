#include<bits/stdc++.h>
using namespace std;
int n,a[503],dp[503][503][503],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(dp,192,sizeof(dp));
	dp[0][0][1]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++)
			for(int k=i-j-1;k<=n;k++)
				dp[i][j+1][k-i+j+2]=max(dp[i][j+1][k-i+j+2],dp[i-1][j][k]+a[i]);
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
				dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]+a[i]);
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
				dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);
	}
	for(int i=0;i<=n;i++)
		ans=max(ans,dp[n][n][i]);
	cout<<ans;
}