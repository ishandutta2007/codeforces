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
const int maxn=2e5+7;
struct Edge{
	int to,w;
	bool operator<(const Edge & a)const{
		return w<a.w;
	}
};
typedef unsigned long long ull;
vc<Edge> G[maxn];
vi deg[10];
int ans=0;
int n,k;
ull st[9][9];
ull val[maxn];
ull tar;
void solve(int cur,ull cc)
{
	if(cur==k)
	{
		ans+=(cc==tar);
		return;
	}
	//dbg(cur);
	//for(int i=0;i<=n;i++) dbg(i,Find(i),sz[i],vis[i]);
	for(int i=0;i<=cur;i++)
		solve(cur+1,cc+st[cur][i]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int m;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		val[i]=rand_int(0,5e18);
		tar+=val[i];
	}
	for(int i=0,u,v,w;i<m;i++)
	{
		cin>>u>>v>>w;
		G[u].push_back(Edge{v,w});
	}
	for(int i=1;i<=n;i++)
	{
		sort(G[i].begin(),G[i].end());
		deg[G[i].size()-1].push_back(i);
	}
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<=i;j++)
		{
			for(auto u:deg[i])
			{
				int to=G[u][j].to;
				st[i][j]+=val[to];
			}
		}
	}
	solve(0,0);
	print(ans);
}