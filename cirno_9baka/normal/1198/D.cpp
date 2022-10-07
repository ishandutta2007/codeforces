#include<stdio.h>
#include<stdlib.h>
#include<set>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int M=998244353;
int n,dp[55][55][55][55],i,j,s[55][55];
char c[55][55];
int dfs(int i,int j,int k,int l)
{
	int p;
	if(dp[i][j][k][l]!=-1)
		return dp[i][j][k][l];
	if(i>j||k>l)
		return 0;
	if(s[j][l]-s[j][k-1]-s[i-1][l]+s[i-1][k-1]==0)
		return dp[i][j][k][l]=0;
	dp[i][j][k][l]=max(j-i+1,l-k+1);
	for(p=i;p<j;p++)
		dp[i][j][k][l]=min(dp[i][j][k][l],dfs(i,p,k,l)+dfs(p+1,j,k,l));
	for(p=k;p<l;p++)
		dp[i][j][k][l]=min(dp[i][j][k][l],dfs(i,j,k,p)+dfs(i,j,p+1,l));
	return dp[i][j][k][l];
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%s",c[i]+1);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			s[i][j]=s[i-1][j]+s[i][j-1]+(c[i][j]=='#')-s[i-1][j-1];
	memset(dp,-1,sizeof(dp));
	cout<<dfs(1,n,1,n);
}