#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[33;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int maxn=2e5+7;
vector<int> G[maxn];
const int mod=998244353;
ll ans=1;
ll fac[maxn];
void db()
{
	fac[0]=1;
	for(int i=1;i<maxn;i++) fac[i]=fac[i-1]*i%mod;
}
ll cnt(int u)
{
	if(u==1)
	{
		return fac[G[u].size()];
	}
	else{
		int son=G[u].size()-1;
		return 1LL*(son+1)*fac[son]%mod;
	}
}
int main()
{
	int n;
	db();
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		ans=ans*cnt(i)%mod;
	ans=ans*n%mod;
	printf("%lld\n",ans);
}