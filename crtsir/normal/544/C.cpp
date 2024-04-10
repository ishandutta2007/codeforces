#include<bits/stdc++.h>
using namespace std;
int n,m,b,mod,a[503],dp[2][503][503],now=1;
int main(){
	cin>>n>>m>>b>>mod;
	for(int i=0;i<n;i++)cin>>a[i];
	dp[0][0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=m;j++)
		{
			for(int k=b;k>=a[i];k--){
				if(!j)
					dp[now][j][k]=dp[now^1][j][k];
				else
					dp[now][j][k]=(dp[now^1][j][k]+dp[now][j-1][k-a[i]])%mod;
			}
			for(int k=a[i]-1;k>=0;k--)
				dp[now][j][k]=dp[now^1][j][k];
		}
		now^=1;
	}
	long long ans=0;
	for(int i=0;i<=b;i++)
		ans=(ans+dp[now^1][m][i])%mod;
	cout<<ans;
}