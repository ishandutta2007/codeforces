#include<bits/stdc++.h>
using namespace std;
long long dp[11][1003],n,m,mod=1000000007,ans;
int main(){
	cin>>n>>m;
	dp[0][1]=1;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int k=0;k<=j;k++)
				dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			ans=(ans+dp[m][i]*dp[m][n-j+1])%mod;
	cout<<ans;
}