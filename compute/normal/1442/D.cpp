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
int sz[3005];
ll pre[3005][3005];
int n,k;
ll ans=0;
void solve(int l,int r,vc<ll>& dp)
{
	if(l==r)
	{
		for(int i=0;i<=sz[l];i++)
			ans=max(ans,pre[l][i]+dp[k-i]);
		return;
	}
	int mid=l+r>>1;
	{
		vc<ll> nxt=dp;
		for(int i=l;i<=mid;i++)
		{
			for(int t=k;t>=sz[i];t--)
				nxt[t]=max(nxt[t],nxt[t-sz[i]]+pre[i][sz[i]]);
		}
		solve(mid+1,r,nxt);
	}
	{
		vc<ll> nxt=dp;
		for(int i=mid+1;i<=r;i++)
		{
			for(int t=k;t>=sz[i];t--)
				nxt[t]=max(nxt[t],nxt[t-sz[i]]+pre[i][sz[i]]);
		}
		solve(l,mid,nxt);
	}
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>n>>k;
	int tt;
	for(int i=0;i<n;i++)
	{
		cin>>sz[i];
		for(int j=1;j<=sz[i];j++)
		{
			if(j>k)
			{
				cin>>tt;
				continue;
			}
			cin>>pre[i][j];
			pre[i][j]+=pre[i][j-1];
		}
		sz[i]=min(k,sz[i]);
	}
	vc<ll> dp(k+1,-1e18);
	dp[0]=0;
	solve(0,n-1,dp);
	print(ans);
}