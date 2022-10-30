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
const int maxn=1005;
const int MAXM=1e5+7;
const int mod=998244353;
int arr[maxn];
ll dp[maxn][maxn];
int n,k;
ll solve(int x)
{
	for(int i=0;i<=k;i++)
		for(int j=0;j<=n;j++)
			dp[i][j]=0;
	for(int i=0;i<=n;i++)
		dp[1][i]=i;
	for(int i=1;i<k;i++)
	{
		int p=0;
		for(int j=0;j<n;j++)
		{
			while(arr[j]-arr[p]>=x) p++;
			dp[i+1][j+1]=(dp[i+1][j]+dp[i][p])%mod;
		}
	}
	return dp[k][n];
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	sort(arr,arr+n);
	ll ans=0;
	for(int i=1;i*(k-1)<=MAXM;i++)
		ans=(ans+solve(i))%mod;
	printf("%lld\n",ans);
}