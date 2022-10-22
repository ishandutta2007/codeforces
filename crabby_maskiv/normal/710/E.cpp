#include<iostream>
using namespace std;
long long dp[20000020];
int n;
int main()
{
	cin>>n;
	int i,x,y;
	cin>>x>>y;
	dp[1]=x;
	for(i=2;i<=20000010;i++) dp[i]=999999999999999;
	for(i=1;i<=n+1;i++)
	{
		dp[i+1]=min(dp[i]+x,dp[i+1]);
		dp[i*2]=min(dp[i]+y,dp[i*2]);
		dp[i*2-1]=min(dp[i]+y+x,dp[i*2-1]);
	}
	cout<<dp[n];
	return 0;
}