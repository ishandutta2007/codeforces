#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=1e9;
int dp[40][40][60];
int t,n,m,k;
int main() 
{
	for (int i=0;i<40;i++)
	{
		for (int j=0;j<40;j++)
		{
			for (int k=0;k<60;k++) 
			{
				if (k==0 || i*j==k) dp[i][j][k]=0; 
				else dp[i][j][k]=INF;
				for (int l=0;l<=k;l++) 
				{
					for (int m=1;m<i;m++)	
					{
						dp[i][j][k] = min(dp[i][j][k],dp[m][j][l]+dp[i-m][j][k-l]+j*j);
					}
					for (int m=1;m<j;m++) 
					{
						dp[i][j][k] = min(dp[i][j][k],dp[i][m][l]+dp[i][j-m][k-l]+i*i);
					}
				}
			}
		}		
	}
		
	cin>>t;
	while (t--)	
	{
		cin>>n>>m>>k;
		cout<<dp[n][m][k]<<endl;	
	}
	return 0;
}