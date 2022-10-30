#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[33;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
}
ll rand_int(ll l, ll r) //[l, r]
{
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution<ll>(l, r)(gen);
}
template<class T>
void print(T x,int suc=1)
{
	cout<<x;
	if(suc==1) cout<<'\n';
	else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
	for(int i=0;i<v.size();i++)
	print(v[i],i==(int)(v.size())-1?suc:2);
}
const int maxn=1e5+7;
struct Edge{
	int to;ll w;
};
vc<Edge> G[maxn];
int n,m,k,q;
int fa[maxn];
int Find(int x)
{
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
	x=Find(x),y=Find(y);
	fa[y]=x;
}
struct D{
	int u;ll dis;
	bool operator<(const D&a) const{
		return dis>a.dis;
	}
};
ll dis[maxn];
int vis[maxn];
void dijkstra()
{
	priority_queue<D> q;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=k;i++)
	{
		dis[i]=0;
		q.push(D{i,0});
	}
	while(!q.empty())
	{
		auto cur=q.top();q.pop();
		int u=cur.u;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto &e:G[u])
		{
			int v=e.to;
			if(dis[v]>dis[u]+e.w)
			{
				dis[v]=dis[u]+e.w;
				q.push(D{v,dis[v]});
			}
		}
	}
}
using tp=tuple<int,int,ll>;
vc<Edge> Tree[maxn];
int fat[maxn][20];
ll mxv[maxn][20];
int dep[maxn];
void dfs(int u,int fa=-1)
{
	for(auto &e:Tree[u])
	{
		int v=e.to;
		if(v==fa) continue;
		fat[v][0]=u;
		mxv[v][0]=e.w;
		for(int j=1;j<20;j++)
		{
			fat[v][j]=fat[fat[v][j-1]][j-1];
			mxv[v][j]=max(mxv[v][j-1],mxv[fat[v][j-1]][j-1]);
		}
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}
ll solve(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	ll ret=0;
	for(int j=19;j>=0;j--)
	{
		if(dep[fat[u][j]]>=dep[v])
		{
			ret=max(ret,mxv[u][j]);
			u=fat[u][j];
		}
	}
	for(int j=19;j>=0;j--)
	{
		if(fat[u][j]!=fat[v][j])
		{
			ret=max({ret,mxv[u][j],mxv[v][j]});
			u=fat[u][j],v=fat[v][j];
		}
	}
	if(u!=v)
		ret=max({ret,mxv[u][0],mxv[v][0]});
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>k>>q;
	vc<tp> edge;
	for(int i=0,u,v,w;i<m;i++)
	{
		cin>>u>>v>>w;
		edge.emplace_back(u,v,w);
		G[u].push_back(Edge{v,w});
		G[v].push_back(Edge{u,w});
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	dijkstra();
	sort(edge.begin(),edge.end(),[&](tp a,tp b){
		ll u,v,w;
		tie(u,v,w)=a;
		ll da=dis[u]+dis[v]+w;
		tie(u,v,w)=b;
		ll db=dis[u]+dis[v]+w;
		return da<db;
	});
	for(auto [u,v,w]:edge)
	{
		if(Find(u)!=Find(v))
		{
			ll cost=dis[u]+dis[v]+w;
			Tree[u].push_back(Edge{v,cost});
			Tree[v].push_back(Edge{u,cost});
			Union(u,v);
		}
	}
	dep[1]=1;
	dfs(1);
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		print(solve(u,v));
	}
	
}