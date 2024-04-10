#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int a[35];
int dp[3][3000];
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<26;i++) cin>>a[i];
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		int len=mod;
		dp[1][i]=-mod;
		dp[2][i]=mod;
		for(int j=i-1;j>=0;--j)
		{
			len=min(len,a[s[j]-'a']);
			if(len>=i-j)
			{
				dp[0][i]=(dp[0][i]+dp[0][j])%mod;
				dp[1][i]=max(dp[1][i],max(i-j,dp[1][j]) );
				dp[2][i]=min(dp[2][i],dp[2][j]+1); 
			} 		
		}
	}
	cout<<dp[0][n]<<endl<<dp[1][n]<<endl<<dp[2][n]<<endl; 
	return 0;
}