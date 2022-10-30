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
const int maxn=605;
ll G[maxn][maxn];
ll cost[maxn][maxn];
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int m;
	cin>>n>>m;
	memset(G,0x3f,sizeof(G));
	memset(cost,0x3f,sizeof(cost));
	for(int i=0,u,v,w;i<m;i++)
	{
		cin>>u>>v>>w;
		G[u][v]=w;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				int cc=(j-k+n)%n;
				cost[i][j]=min(cost[i][j],G[i][k]+cc);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		vc<ll> dis(n,1e18);
		vi vis(n);
		dis[i]=0;
		for(int j=0;j<n;j++)
		{
			int u=0;
			ll d=1e18;
			for(int k=0;k<n;k++)
			{
				if(!vis[k]&&dis[k]<d)
				{
					u=k;
					d=dis[k];
				}
			}
			vis[u]=1;
			for(int k=0;k<n;k++)
			{
				int cc=(k-dis[u]%n+n)%n;
				dis[k]=min(dis[k],dis[u]+cost[u][cc]);
			}
		}
		print(dis);
	}
}