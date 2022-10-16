// 228
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,mod=1e9+7;
int t,n,k,dp[N][N];
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1;i<=k;i++)dp[0][i]=1;
		
		for(int j=1;j<=k;j++)
			for(int i=1;i<=n;i++)
				dp[i][j]=(dp[n-i][j-1]+dp[i-1][j])%mod;
				
		cout<<dp[n][k]<<endl;
	}
	return 0;
}