#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
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
int n,m;
const int maxn=2e5+7;
const int mod=998244353;
struct Edge{
	int to,w;
};
pi edge[maxn];
vc<Edge> G[maxn*2],g[maxn*20];
struct D{
	ll d;int id;
	bool operator<(const D &a)const{
		return d>a.d;
	}
};
ll dis[maxn*20];
int vis[maxn*20];
void dij()
{
	priority_queue<D> q;
	for(int i=0;i<=n*20;i++) dis[i]=1e18;
	memset(vis,0,sizeof(vis));
	dis[1]=0;
	q.push(D{0,1});
	while(!q.empty())
	{
		auto cur=q.top();q.pop();
		int u=cur.id;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto &e:g[u])
		{
			int v=e.to;
			if(dis[v]>dis[u]+e.w)
			{
				dis[v]=dis[u]+e.w;
				q.push(D{dis[v],v});
			}
		}
	}
	ll ans=1e18;
	for(int j=0;j<20;j++) ans=min(ans,dis[j*n+n]);
	if(ans<1e9)
	{
		print(ans);
		exit(0);
	}
}
void dij2()
{
	priority_queue<D> q;
	for(int i=0;i<=n*2;i++) dis[i]=1e18;
	memset(vis,0,sizeof(vis));
	dis[1]=0;
	q.push(D{0,1});
	while(!q.empty())
	{
		auto cur=q.top();q.pop();
		int u=cur.id;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto &e:G[u])
		{
			int v=e.to;
			if(dis[v]>dis[u]+e.w)
			{
				dis[v]=dis[u]+e.w;
				q.push(D{dis[v],v});
			}
		}
	}
	ll ans=min(dis[n],dis[n*2]);
	int ti=ans/1000000000;
	ans=ans%1000000000;
	ll cur=1;
	for(int i=0;i<ti;i++)
	{
		ans=(ans+cur)%mod;
		cur=cur*2%mod;
	}
	ans%=mod;
	print(ans);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0,u,v;i<m;i++)
	{
		cin>>u>>v;
		edge[i]={u,v};
		for(int j=0;j<20;j++)
		{
			if(j&1^1)
				g[u+j*n].push_back(Edge{v+j*n,1});
			else g[j*n+v].push_back(Edge{j*n+u,1});
		}
		G[u].push_back(Edge{v,1});
		G[v+n].push_back(Edge{u+n,1});
	}
	for(int j=0;j<19;j++)
	for(int i=1;i<=n;i++)
		g[i+j*n].push_back(Edge{i+(j+1)*n,1<<j});
	for(int i=1;i<=n;i++)
	{
		G[i].push_back(Edge{i+n,1000000000});
		G[i+n].push_back(Edge{i,1000000000});
	}
	dij();
	dij2();
}