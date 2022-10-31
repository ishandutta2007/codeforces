#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int maxn=205;
vector<int> G[maxn];
int a[maxn];
int dp[maxn][maxn];
int n,k;
void dfs(int u,int fa=-1)
{
	for(int i=1;i<=n;i++) dp[u][i]=-INF;
	dp[u][n+1]=0;
	dp[u][0]=a[u];
	for(auto v:G[u])if(v!=fa)
	{
		dfs(v,u);
		vector<int> newdp(n+2);
		newdp[0]=dp[u][0];
		for(int i=1;i<=n+1;i++) newdp[i]=min(dp[u][i],dp[v][i-1]);
		for(int i=0;i<=n+1;i++)
		{
			for(int j=max(0,k-i);j<=n+1;j++)
			{
				newdp[min(i,j+1)]=max(dp[u][i]+dp[v][j],newdp[min(i,j+1)]);
			}
		}
		for(int i=0;i<=n+1;i++) dp[u][i]=newdp[i];
	}
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1,u,v;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	int ans=-1;
	for(int i=0;i<=n;i++) ans=max(ans,dp[1][i]);
	cout<<ans<<endl;
}