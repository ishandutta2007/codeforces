//This code was made by Chinese_zjc_.
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<iomanip>
#include<stack>
#include<bitset>
#define int long long
#define INF 0x3fffffffffffffff
using namespace std;
int n,a[505],dp[505][505];
int dfs(int l,int r)
{
	if(~dp[l][r])
	{
		return dp[l][r];
	}
	dp[l][r]=INF;
	if(l==r)
	{
		return dp[l][r]=1;
	}
	if(l+1==r)
	{
		if(a[l]==a[r])
		{
			return dp[l][r]=1;
		}
		else
		{
			return dp[l][r]=2;
		}
	}
	if(a[l]==a[r])
	{
		dp[l][r]=dfs(l+1,r-1);
	}
	for(int i=l;i<r;++i)
	{
		dp[l][r]=min(dp[l][r],dfs(l,i)+dfs(i+1,r));
	}
	return dp[l][r];
}
signed main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	memset(dp,-1,sizeof(dp));
	cout<<dfs(1,n)<<endl;
	return 0;
}