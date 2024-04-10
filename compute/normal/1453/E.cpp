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
vi G[maxn];
int n;
int dp[maxn];
bool suc;
int k;
void dfs(int u,int fa=-1)
{
	int mi=1e9,mx=0;
	int cc=0;
	for(auto v:G[u])if(v!=fa)
	{
		dfs(v,u);
		if(dp[v]>k-1) cc++;
		mx=max(mx,dp[v]);
		mi=min(mi,dp[v]);
	}
	if(mx>k-(fa!=-1)) suc=0;
	if(fa==-1)
	{
		if(cc>1) suc=0;
		if(cc==1&&mx>k) suc=0;
	}
	if(mi>1e8) mi=0;
	dp[u]=mi+1;
	//dbg(u,dp[u]);
}
bool check(int x)
{
	k=x;
	suc=1;
	dfs(1);
	//dbg(x,suc);
	return suc;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=0;i<=n;i++) G[i].clear();
		for(int i=1,u,v;i<n;i++)
		{
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int L=1,R=n,ans=-1;
		while(L<=R)
		{
			int mid=L+R>>1;
			if(check(mid))
			{
				R=mid-1;
				ans=mid;
			}
			else L=mid+1;
		}
		print(ans);
	}
}