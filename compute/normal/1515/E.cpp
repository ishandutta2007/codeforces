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
const int maxn=405;
int mod;
int dp[maxn][maxn];
int C[maxn][maxn];
int two[maxn];
int calc(int x)
{
	return two[x-1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n;
	cin>>n>>mod;
	two[0]=1;
	for(int i=1;i<maxn;i++) two[i]=two[i-1]*2%mod;
	for(int i=0;i<maxn;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			for(int k=1;j+k<i;k++)
				dp[i][j+k]=(dp[i][j+k]+1LL*C[j+k][k]*dp[i-k-1][j]%mod*calc(k)%mod)%mod;
		}
		dp[i][i]=calc(i);
		//for(int j=0;j<=i;j++) dbg(i,j,dp[i][j]);
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
		ans=(ans+dp[n][i])%mod;
	print(ans);
}