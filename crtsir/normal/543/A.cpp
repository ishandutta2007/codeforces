#include<bits/stdc++.h>
using namespace std;
int dp[2][503][503],mod,n,m,d,a[503];
bool last,cur=1; 
int main(){
	cin>>n>>m>>d>>mod;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int k=d;k>=a[i];k--)
				if(j==0)
					dp[cur][j][k]=dp[last][j][k];
				else
					dp[cur][j][k]=(dp[last][j][k]+dp[cur][j-1][k-a[i]])%mod;
			for(int k=a[i]-1;k>=0;k--)
				dp[cur][j][k]=dp[last][j][k];
		}
		last^=1;
		cur^=1;
	}
	int ans=0;
	for(int i=0;i<=d;i++)
		ans=(ans+dp[last][m][i])%mod;
	cout<<ans;
}