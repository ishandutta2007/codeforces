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
int a[3005];
int dp[3005][3005];
int cost[3005];
int n;

void solve()
{
	cin>>n;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++) dp[i][j]=1e9;
	vc<vi> r(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		r[i+a[i]].push_back(i);
	}
	dp[0][0]=0;
	r[1].push_back(0);
	for(int i=1;i<=n;i++)
	{
		cost[i-1]=0;
		for(int j=i-1;j>=1;j--)
			cost[j-1]=cost[j]+((j+a[j])>=i);
		int mi=1e9;
		for(int j=i;j<=n;j++)
		{
			for(auto l:r[j])
			{
				if(l<i)
					mi=min(mi,dp[l][i-1]+cost[l]);
			}
			dp[i][j]=mi;
		}
	}
	print(dp[n][n]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--) solve();
}