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
const int maxn=2e3+7;
vi G[maxn];
vi all;
int vis[maxn];
void dfs(int u,int d=0,int fa=-1)
{
	vis[u]=1;
	int fi=0;
	for(auto v:G[u])
	{
		if(u==1&&vis[v]) continue;
		if(v==fa&&!fi)
		{
			fi++;
			continue;
		}
		if(v==1) all.push_back(d+1);
		else dfs(v,d+1,u);
	}
}
const int mod=1e9+7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=0,u,v;i<m;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	int sum=accumulate(all.begin(),all.end(),0);
	vc<ll> dp(sum*4+1);
	const int var=2*sum;
	dp[var]=1;
	auto add=[&](int u){
		for(int i=u;i<=4*sum;i++)
		{
			dp[i-u]=(dp[i-u]+dp[i])%mod;
			if(i>=2*u)
				dp[i-2*u]=(dp[i-2*u]+dp[i])%mod;
		}
		for(int i=4*sum-u;i>=0;i--)
			dp[i+u]=dp[i];
		for(int i=0;i<u;i++) dp[i]=0;
	};
	auto del=[&](int u){
		for(int i=u;i<=4*sum;i++)
			dp[i-u]=dp[i]%mod;
		for(int i=4*sum-u+1;i<=4*sum;i++) dp[i]=0;
		for(int i=4*sum;i>=u;i--)
		{
			dp[i-u]=(dp[i-u]-dp[i]+mod)%mod;
			if(i>=2*u) dp[i-2*u]=(dp[i-2*u]-dp[i]+mod)%mod;
		}
	};
	for(auto u:all)
		add(u);
	ll ans=0;
	for(auto u:all)
	{
		del(u);
		for(int i=var-u+2;i<var+u-1;i++)
			ans=(ans+dp[i]*2%mod)%mod;
		add(u);
	}
	vc<ll> ext(sum*2+1);
	ext[sum]=1;
	auto add2=[&](int u){
		vc<ll> nxt(sum*2+1);
		for(int i=0;i<=sum*2;i++)
		{
			if(i>=u) nxt[i]+=ext[i-u];
			if(i+u<=sum*2) nxt[i]+=ext[i+u];
			nxt[i]%=mod;
		}
		ext=nxt;
	};
	auto del2=[&](int u){
		vc<ll> nxt(sum*2+1);
		for(int i=0;i<=sum*2-2*u;i++)
		{
			nxt[i+u]=ext[i];
			ext[2*u+i]=(ext[2*u+i]-ext[i]+mod)%mod;
		}
		for(int i=sum*2-2*u+1;i<=sum*2-u;i++) nxt[i+u]=ext[i];
		ext=nxt;
	};
	for(auto u:all)
		add2(u);
	if(sum&1) {
		for(auto u:all)
		{
			del2(u);
			ans=(ans+ext[sum-u+1]*2+ext[sum+u-1]*2)%mod;
			add2(u);
		}
	}
	else ans=(ans+ext[sum])%mod;
	print(ans);
}