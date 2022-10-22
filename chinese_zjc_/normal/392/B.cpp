//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int s[4][4],dp[50][4][4],n;
int dfs(int now,int f,int t)
{
	if(dp[now][f][t])
	{
		return dp[now][f][t];
	}
	if(now==1)
	{
		return dp[now][f][t]=min(s[f][t],s[f][f^t]+s[f^t][t]);
	}
	if(f==1)
	{
		if(t==1)
		{
			return 0;
		}
		if(t==2)
		{
			return dp[now][f][t]=min(dfs(now-1,1,2)+s[1][3]+dfs(now-1,2,1)+s[3][2]+dfs(now-1,1,2),dfs(now-1,1,3)+s[1][2]+dfs(now-1,3,2));
		}
		if(t==3)
		{
			return dp[now][f][t]=min(dfs(now-1,1,3)+s[1][2]+dfs(now-1,3,1)+s[2][3]+dfs(now-1,1,3),dfs(now-1,1,2)+s[1][3]+dfs(now-1,2,3));
		}
	}
	if(f==2)
	{
		if(t==1)
		{
			return dp[now][f][t]=min(dfs(now-1,2,1)+s[2][3]+dfs(now-1,1,2)+s[3][1]+dfs(now-1,2,1),dfs(now-1,2,3)+s[2][1]+dfs(now-1,3,1));
		}
		if(t==2)
		{
			return 0;
		}
		if(t==3)
		{
			return dp[now][f][t]=min(dfs(now-1,2,3)+s[2][1]+dfs(now-1,3,2)+s[1][3]+dfs(now-1,2,3),dfs(now-1,2,1)+s[2][3]+dfs(now-1,1,3));
		}
	}
	if(f==3)
	{
		if(t==1)
		{
			return dp[now][f][t]=min(dfs(now-1,3,1)+s[3][2]+dfs(now-1,1,3)+s[2][1]+dfs(now-1,3,1),dfs(now-1,3,2)+s[3][1]+dfs(now-1,2,1));
		}
		if(t==2)
		{
			return dp[now][f][t]=min(dfs(now-1,3,2)+s[3][1]+dfs(now-1,2,3)+s[1][2]+dfs(now-1,3,2),dfs(now-1,3,1)+s[3][2]+dfs(now-1,1,2));
		}
		if(t==3)
		{
			return 0;
		}
	}
	return -INF;
}
signed main()
{
	std::ios::sync_with_stdio(false);
	for(int i=1;i<=3;++i)
	{
		for(int j=1;j<=3;++j)
		{
			cin>>s[i][j];
		}
	}
	cin>>n;
	cout<<dfs(n,1,3)<<endl;
	return 0;
}