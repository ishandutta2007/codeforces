#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int dp[600][302][302];
int main()
{
	int mx;
	scanf("%d",&mx);
	int map[300][300];
	for(int i=0;i<mx;i++)
	{
		for(int j=0;j<mx;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	for(int i=0;i<mx*2;i++)
	{
		for(int j=0;j<mx+2;j++)
		{
			for(int k=0;k<mx+2;k++)
			{
				dp[i][j][k]=-2000000000;
			}
		}
	}
	for(int i=0;i<mx+2;i++)
	{
		for(int j=0;j<mx+2;j++)
		{
			dp[0][i][j]=0;
		}
	}
	for(int i=0;i<mx*2-1;i++)
	{
		for(int j=max(0,i-mx+1);j<=min(i,mx-1);j++)
		{
			for(int k=max(0,i-mx+1);k<=min(i,mx-1);k++)
			{
				if(j==k)
				{
					dp[i+1][j+1][k+1]=max(max(dp[i][j][k],dp[i][j+1][k]),max(dp[i][j+1][k+1],dp[i][j][k+1]))+map[i-j][j];
				}
				else
				{
					dp[i+1][j+1][k+1]=max(max(dp[i][j][k],dp[i][j+1][k]),max(dp[i][j+1][k+1],dp[i][j][k+1]))+map[i-j][j]+map[i-k][k];
				}
				//printf("%d ",dp[i+1][j+1][k+1]);
			}
			//printf("\n");
		}
		//printf("\n");
	}
	printf("%d\n",dp[mx*2-1][mx][mx]);
}