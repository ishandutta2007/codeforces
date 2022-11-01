#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[40][40];
//nnnh-1
int main()
{
	int n,h;
	cin>>n>>h;
	for(int i=1;i<=n;i++)// 
	{  
		dp[0][i-1] = 1;
		for(int j=1;j<=n;j++)//n
		{
			for(int k=0;k<j;k++)// 
			{
				dp[j][i] += dp[k][i-1] * dp[j-k-1][i-1];
			}
		}		
	}
	cout<<dp[n][n]-dp[n][h-1]<<endl;
	return 0;
}