#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int hai[1000];
int dp[2][1001][1001];
int main()
{
	int mx,my,lb,ub;
	scanf("%d%d%d%d",&mx,&my,&lb,&ub);
	for(int i=0;i<mx;i++)
	{
		for(int j=0;j<my;j++)
		{
			char zan;
			scanf(" %c",&zan);
			if(zan=='#')
			{
				hai[j]++;
			}
		}
	}
	for(int i=0;i<my;i++)
	{
		for(int j=1;j<=min(ub,i+1);j++)
		{
			dp[0][i+1][j]=dp[0][i][j-1]+mx-hai[i];
			dp[1][i+1][j]=dp[1][i][j-1]+hai[i];
		}
		dp[0][i+1][0]=1000000000;
		dp[1][i+1][0]=1000000000;
		for(int j=lb;j<=min(ub,i+1);j++)
		{
			dp[0][i+1][0]=min(dp[0][i+1][0],dp[1][i+1][j]);
			dp[1][i+1][0]=min(dp[1][i+1][0],dp[0][i+1][j]);
		}
	}
	int mini=1000000000;
	for(int i=lb;i<=min(ub,my);i++)
	{
		mini=min(mini,dp[0][my][i]);
		mini=min(mini,dp[1][my][i]);
	}
	printf("%d\n",mini);
}