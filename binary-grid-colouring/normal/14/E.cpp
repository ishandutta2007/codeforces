#include<bits/stdc++.h>
using namespace std;
int dp[23][23][23][2];
//dp[n][t][j][s] n,tjs10.
int main()
{
	for(int i=1;i<5;i++)
	{
		dp[1][1][i][1] = 1;// 1 
	}
	
	for(int k=2;k<=20;k++)
	{
		for(int l=1;l<=10;l++)
		{
			for(int i=1;i<=4;i++)
			{
				for(int j=1;j<i;j++)//: 1 2 
				{
					dp[k][l][i][1] += (dp[k-1][l-1][j][0] + dp[k-1][l][j][1]); 
				}
				if(k==2)//2 
				{
					dp[k][l][i][0] = 0;
				}
				else
				{
					for(int j=i+1;j<=4;j++)
					{
						//(1:,2:)
						dp[k][l][i][0] += (dp[k-1][l][j][0] + dp[k-1][l][j][1]);
					}
				} 
			}	
		}
		
		
	}
	int n , t;
	cin>>n>>t;
	int ans = 0;
	for(int i=1;i<=4;i++)
	{
		ans += dp[n][t][i][0];
	}
	cout<<ans<<endl;
	return 0;
}