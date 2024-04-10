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
const int maxn=2e5+7;
struct Edge{
	int to,w;
};
vc<Edge> G[maxn];
ll dis[maxn][4];
int vis[maxn][4];
struct D{
	int u,st; ll dis;
	bool operator<(const D&a)const{
		return dis>a.dis;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=0,u,v,w;i<m;i++)
	{
		cin>>u>>v>>w;
		G[u].push_back(Edge{v,w});
		G[v].push_back(Edge{u,w});
	}
	memset(dis,0x3f,sizeof(dis));
	dis[1][0]=0;
	priority_queue<D> q;
	q.push({1,0,0});
	auto upd=[&](int v,int st,ll d){
		if(dis[v][st]>d)
		{
			dis[v][st]=d;
			q.push({v,st,d});
		}
	};
	while(!q.empty())
	{
		auto cur=q.top();q.pop();
		int u=cur.u,st=cur.st;
		if(vis[u][st]) continue;
		vis[u][st]=1;
		for(auto &e:G[u])
		{
			int v=e.to;
			ll d=dis[u][st]+e.w;
			if(st&1^1)
				upd(v,st|1,d-e.w);
			if(st>>1&1^1)
				upd(v,st|2,d+e.w);
			if(st==0) upd(v,3,d);
			upd(v,st,d);
		}
	}
	for(int i=2;i<=n;i++) cout<<dis[i][3]<<" \n"[i==n];
}