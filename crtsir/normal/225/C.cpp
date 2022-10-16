#include<bits/stdc++.h>
using namespace std;
int dp[2][1003],n,m,a,b,qzh[2][1003];
char c;
int main(){
	cin>>n>>m>>a>>b;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>c;
			if(c=='.')qzh[0][j]++;else qzh[1][j]++;
		}
	for(int i=2;i<=m;i++)
		qzh[0][i]+=qzh[0][i-1],
		qzh[1][i]+=qzh[1][i-1];
	dp[0][0]=0;
	dp[1][0]=0;
	for(int i=1;i<=m;i++)dp[0][i]=10000000,dp[1][i]=10000000;
	for(int i=a;i<=m;i++)
	{
		for(int j=a;j<=b&&i>=j;j++)
			dp[0][i]=min(dp[1][i-j]+qzh[0][i]-qzh[0][i-j],dp[0][i]),
			dp[1][i]=min(dp[0][i-j]+qzh[1][i]-qzh[1][i-j],dp[1][i]);
	}
	cout<<min(dp[0][m],dp[1][m]);
}