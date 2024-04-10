#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[33;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int maxn=3e5+7;
vector<int> G[maxn];
int col[maxn];
int red,blue;
int ans;
pair<int,int> dfs(int u,int fa)
{
	pair<int,int> ret={0,0};
	if(col[u]==1) ret.first++;
	else if(col[u]==2) ret.second++;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa) continue;
		auto cur=dfs(v,u);
		if((cur.first==red&&cur.second==0)||(cur.first==0&&cur.second==blue)) ans++;
		ret.first+=cur.first;
		ret.second+=cur.second;
	}
	return ret;

}
int main()
{
	int n;
	scanf("%d",&n);
	red=0,blue=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&col[i]);
		if(col[i]==1) red++;
		else if(col[i]==2) blue++;
	}
	for(int i=0,u,v;i<n-1;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,-1);
	printf("%d\n",ans);
}