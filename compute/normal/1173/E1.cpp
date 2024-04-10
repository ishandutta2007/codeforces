#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
const int maxn=55;
const int mod=998244353;
int like[maxn];
ll dp[maxn*2][maxn][maxn][2];
int wi[maxn];
int n,m;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
bool cur=0;
int suma=0,sumb=0;
ll dfs(int w,int k,int j)
{
	if(k+j==m) return w;
	if(w<=0) return 0;
	if(dp[w][k][j][cur]) return dp[w][k][j][cur];
	ll &ret=dp[w][k][j][cur];
	ll ud=inv(suma+k+sumb-j);
	ll curk=k+suma,curj=-j+sumb;
	if(cur)
	{
		ret=1LL*w*ud%mod*dfs(w+1,k+1,j)%mod;
		ret=(ret+1LL*(curk-w+mod)*ud%mod*dfs(w,k+1,j)%mod)%mod;
		ret=(ret+curj*ud%mod*dfs(w,k,j+1)%mod)%mod;
	}
	else{
		ret=1LL*w*ud%mod*dfs(w-1,k,j+1)%mod;
		ret=(ret+1LL*(curj-w+mod)*ud%mod*dfs(w,k,j+1)%mod)%mod;
		ret=(ret+1LL*curk*ud%mod*dfs(w,k+1,j)%mod)%mod;
	}
	dbg(w,k,j,curk,curj,ret);
	return ret;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&like[i]);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&wi[i]);
		if(like[i]) suma+=wi[i];
		else sumb+=wi[i];
	}
	dbg(suma,sumb);
	for(int i=0;i<n;i++)
	{
		cur=like[i];
		printf("%lld\n",dfs(wi[i],0,0));
	}
}