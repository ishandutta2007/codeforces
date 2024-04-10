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
const int maxn=5e6+100;
list<int> G[maxn];
typedef vector<int> vi;
char sch[55];
int cur,scc;
stack<int> st;
int dfn[maxn],low[maxn],bel[maxn];
int n,m,d;
void dfs(int u)
{
	dfn[u]=low[u]=++cur;
	st.push(u);
	for(auto v:G[u])
	{
		if(!dfn[v])
		{
			dfs(v);
			low[u]=min(low[v],low[u]);
		}
		else if(!bel[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		scc++;
		while(1)
		{
			int t=st.top();
			st.pop();
			bel[t]=scc;
			//idx[scc].push_back(t);
			if(t==u) break;
		}
	}
}
int cnt[maxn];
list<int> newg[maxn];
void SCC()
{
	for(int i=0;i<n*d;i++)
		if(!dfn[i])
			dfs(i);
	memset(dfn,0,sizeof(dfn));
	for(int i=0;i<n*d;i++)
	{
		for(auto v:G[i])
		{
			if(bel[i]!=bel[v])
			{
				newg[bel[v]].push_back(bel[i]);
				dfn[bel[i]]++;
			}
		}
	}
}
inline int getid(int i,int j)
{
	return (i-1)*d+j%d;
}

int dp[maxn];
int solve()
{
	queue<int> q;
	for(int i=1;i<=scc;i++)
		if(!dfn[i])
		{
			q.push(i);
			dp[i]=cnt[i];
		}
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(auto v:newg[u])
		{
			dp[v]=max(dp[v],dp[u]+cnt[v]);
			dfn[v]--;
			if(!dfn[v]) q.push(v);
		}
	}
	return dp[bel[0]];
}
int main()
{
	scanf("%d%d%d",&n,&m,&d);
	for(int i=0,u,v;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		for(int j=0;j<d;j++)
			G[getid(u,j)].push_back(getid(v,j+1));
	}
	SCC();
	vector<bool> vis(scc+1,0);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",sch);
		for(int j=0;j<d;j++)
		{
			int id=getid(i,j);
			if(sch[j]=='1'&&!vis[bel[id]])
			{
				vis[bel[id]]=1;
				cnt[bel[id]]++;
			}
		}
		for(int j=0;j<d;j++)
			vis[bel[getid(i,j)]]=0;
	}
	printf("%d\n",solve());
}