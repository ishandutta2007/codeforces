#include<iostream>
using namespace std;
int a[101],b[101];
int dp[105][20003];
int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=0;i<105;i++)
		for(int j=0;j<20003;j++)	
			dp[i][j]=-1000000000;
	dp[0][10000]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=20000;j++)
		{
			if(dp[i+1][j]<dp[i][j])dp[i+1][j]=dp[i][j];
			int f=a[i+1]-b[i+1]*k;
			if(j+f<=20000&&j+f>=0)
				if(dp[i+1][j+f]<a[i+1]+dp[i][j])
					dp[i+1][j+f]=a[i+1]+dp[i][j];
		}
	}
	cout<<(dp[n][10000]<=0?-1:dp[n][10000]);
}