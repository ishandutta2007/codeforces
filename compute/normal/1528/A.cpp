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
vi G[maxn];
int l[maxn],r[maxn];
ll dp[maxn][2];
void dfs(int u,int fa=-1)
{
	dp[u][0]=dp[u][1]=0;
	for(auto v:G[u])if(v!=fa)
	{
		dfs(v,u);
		dp[u][0]=dp[u][0]+max(dp[v][1]+abs(r[v]-l[u]),dp[v][0]+abs(l[v]-l[u]));
		dp[u][1]=dp[u][1]+max(dp[v][1]+abs(r[v]-r[u]),dp[v][0]+abs(l[v]-r[u]));
	}
}
void solve()
{
	int n;
	cin>>n;
	for(int i=0;i<=n;i++) G[i].clear();
	for(int i=1;i<=n;i++)
		cin>>l[i]>>r[i];
	for(int i=1,u,v;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	print(max(dp[1][0],dp[1][1]));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
		solve();
}