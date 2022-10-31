#include<bits/stdc++.h>
using namespace std;
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
const int maxn=2e5+7;
struct Edge{
	int to,num;
};
vector<Edge> G[maxn];
int col[maxn];
int ans[maxn];
int n,k;
int tot;
int dfs(int u,int fa,int fcol)
{
	int cnt=0;
	int ret=0;
	for(int i=0;i<G[u].size();i++)
	{
		Edge v=G[u][i];
		cnt++;
		if(v.to==fa) continue;
		col[v.num]=fcol%tot+1;
		fcol=col[v.num];
		ret+=dfs(v.to,u,col[v.num]);
	}
	return ret+(cnt>tot);
}
bool check(int cur)
{
	tot=cur;
	dbg(cur);
	return dfs(1,-1,0)<=k;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0,u,v;i<n-1;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(Edge{v,i});
		G[v].push_back(Edge{u,i});
	}
	int l=1,r=n,num=1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))
		{
			r=mid-1,num=mid;
			for(int i=0;i<n-1;i++) ans[i]=col[i];
		}
		else l=mid+1;
	}
	printf("%d\n",num);
	for(int i=0;i<n-1;i++) printf("%d ",ans[i]);
	puts("");
}