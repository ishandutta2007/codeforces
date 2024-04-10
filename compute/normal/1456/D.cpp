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
const int maxn=5e3+7;
ll t[maxn],x[maxn];
bool dp[maxn][maxn];
ll mt[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>t[i]>>x[i];
	auto dis=[&](int i,int j){
		return abs(x[i]-x[j]);
	};
	memset(mt,0x3f,sizeof(mt));
	mt[0]=0;
	for(int i=1;i<=n;i++)
	{
		mt[i]=min(mt[i],max(t[i-1],mt[i-1]+dis(i-1,i)));
		if(mt[i]>t[i]) mt[i]=0x3f3f3f3f3f3f3f3f;
		for(int j=i+1;j<=n;j++)
		{
			ll ti=max(mt[i-1]+dis(i-1,j),t[i-1])+dis(j,i);
			if(ti<=t[i]) dp[i][j]=1;
			if(dp[i-1][j]&&dis(i-1,i)+t[i-1]<=t[i]) dp[i][j]=1;
			dbg(i,j,dp[i][j]);
		}
		if(dp[i-1][i]){
			mt[i+1]=max(t[i],t[i-1]+dis(i-1,i+1));
			for(int j=i+2;j<=n;j++)
			{
				ll ti=max(t[i],t[i-1]+dis(i-1,j))+dis(j,i+1);
				if(ti<=t[i+1]) dp[i+1][j]=1;
			}
		}
		dbg(i,mt[i]);
	}
	if(dp[n-1][n]||mt[n]<=t[n]) cout<<"YES\n";
	else cout<<"NO\n";
}