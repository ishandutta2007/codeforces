#include<iostream>
#include<algorithm>
using namespace std;
int num[160];
int dp[2][160][13000];
const int inf=1000000000;
int main()
{
	int n,k,s;
	cin>>n>>k>>s;
	for(int i=1;i<=n;i++)
		cin>>num[i];
	s=min(s,n*(n-1)/2);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=s;j++)
			dp[0][i][j]=inf;
	int now=0,next=1;
	for(int x=n;x>=1;x--)
	{
		for(int i=1;i<=n;i++)
			for(int j=0;j<=s;j++)
				dp[next][i][j]=inf;
		for(int i=0;i<=min(n-x,k);i++)
			for(int j=0;j<=s;j++)
			{
				dp[next][i][j]=min(dp[now][i][j],dp[next][i][j]);
				if(x<=k-i)
					dp[next][i+1][j]=min(dp[next][i+1][j],dp[now][i][j]+num[x]);
				else
					if(j+x-(k-i)<=s)
						dp[next][i+1][j+x-(k-i)]=min(dp[next][i+1][j+x-(k-i)],dp[now][i][j]+num[x]);
			}
		swap(now,next);
	}
	int ans=inf;
	for(int i=0;i<=s;i++)
	{
		//cout<<dp[now][k][i]<<endl;
		ans=min(ans,dp[now][k][i]);
	}
	cout<<ans;
}