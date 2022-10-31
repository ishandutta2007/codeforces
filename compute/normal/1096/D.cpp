#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
const long long INF=0x3f3f3f3f3f3f3f3f;
int arr[maxn];
long long dp[maxn][5];
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	memset(dp,0x3f,sizeof(dp));
	string s1="hard";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	dp[0][0]=dp[0][1]=dp[0][2]=dp[0][3]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(s[i-1]==s1[j])
			{
				if(j==0) dp[i][j]=dp[i-1][j]+arr[i-1];
				else dp[i][j]=min(dp[i-1][j]+arr[i-1],dp[i-1][j-1]);
			}
			else dp[i][j]=dp[i-1][j];
			//cout<<i<<","<<j<<":"<<dp[i][j]<<endl;
		}
	}
	long long ans=0x3f3f3f3f3f3f3f3f;
	for(int i=0;i<4;i++)
		ans=min(ans,dp[n][i]);
	cout<<ans<<endl;
}