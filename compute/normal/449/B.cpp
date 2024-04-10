#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
const int mod=998244353;
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
const int maxn=1e5+7;
struct SV{
	int u,v,w;
}edges[maxn*4];
struct Edge{
	int to,w;
};
ll dis[maxn];
vector<Edge> G[maxn];
struct Heap_node{
	int u;ll d;
	bool operator<(const Heap_node a)const{
		return d>a.d;
	}
};
bool vis[maxn];
void dijstra()
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	priority_queue<Heap_node> q;
	q.push(Heap_node{1,0});
	while(!q.empty())
	{
		auto u=q.top();q.pop();
		if(vis[u.u]) continue;
		vis[u.u]=1;
		for(auto &e:G[u.u])
		{
			int v=e.to;
			if(dis[v]>u.d+e.w)
			{
				dis[v]=u.d+e.w;
				q.push({v,dis[v]});
			}
		}
	}
}
int cnt[maxn];
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0,u,v,w;i<m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		edges[i]={u,v,w};
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	for(int i=0,v,w;i<k;i++)
	{
		scanf("%d%d",&v,&w);
		edges[i+m]={1,v,w};
		G[1].push_back({v,w});
		G[v].push_back({1,w});
	}
	dijstra();
	int ans=0;
	for(int i=0;i<k;i++)
	{
		int v=edges[m+i].v;
		if(dis[v]<edges[m+i].w) ans++;
		else cnt[v]++;
	}
	for(int i=0;i<m;i++)
	{
		int u=edges[i].u,v=edges[i].v,w=edges[i].w;
		if(dis[u]>dis[v]) swap(u,v);
		if(dis[v]==dis[u]+w)
		{
			ans+=cnt[v];
			cnt[v]=0;
		}
	}
	for(int i=1;i<=n;i++)
		if(cnt[i]) ans+=cnt[i]-1;
	printf("%d\n",ans);
}