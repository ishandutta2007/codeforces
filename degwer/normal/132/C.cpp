#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int dp[101][51][2];
int main()
{
	string str;
	cin>>str;
	int num;
	scanf("%d",&num);
	for(int i=0;i<101;i++)
	{
		for(int j=0;j<51;j++)
		{
			dp[i][j][0]=dp[i][j][1]=-100000000;
		}
	}
	dp[0][0][0]=dp[0][0][1]=0;
	for(int i=0;i<str.size();i++)
	{
		for(int j=0;j<=num;j++)
		{
			if(str[i]=='F')
			{
				dp[i+1][j][0]=dp[i][j][0]+1;
				dp[i+1][j][1]=dp[i][j][1]-1;
			}
			else
			{
				dp[i+1][j][0]=dp[i][j][1];
				dp[i+1][j][1]=dp[i][j][0];
			}
			if(j!=0)
			{
				if(str[i]=='T')
				{
					dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j-1][0]+1);
					dp[i+1][j][1]=max(dp[i+1][j][1],dp[i][j-1][1]+1);
				}
				else
				{
					dp[i+1][j][0]=max(dp[i+1][j][0],dp[i][j-1][1]);
					dp[i+1][j][1]=max(dp[i+1][j][1],dp[i][j-1][0]);
				}
			}
		}
	}
	int maxi=0;
	for(int i=num;i>=0;i-=2)
	{
		maxi=max(maxi,dp[str.size()][i][0]);
		maxi=max(maxi,dp[str.size()][i][1]);
	}
	printf("%d\n",maxi);
}