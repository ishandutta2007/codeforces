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
const int mod=1e9+7;
int quick(int a,int b)
{
	int ret=1;
	while(b)
	{
		if(b&1) ret=1LL*ret*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ret;
}
const int maxn=255;
int C[maxn][maxn];
int powk[maxn];
int powkm[maxn];
int n,kk;
void db()
{
	for(int i=0;i<maxn;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	for(int i=0;i<=n;i++)
	{
		powk[i]=quick(kk,i);
		powkm[i]=quick(kk-1,i);
	}
}
int dp[maxn][maxn];
int main()
{
	scanf("%d%d",&n,&kk);
	db();
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<j;k++)
			{
				dp[i][j]=(dp[i][j]+1LL*C[n-k][j-k]*dp[i-1][k]%mod*powk[k]%mod*powkm[n-j]%mod)%mod;
	//		dbg(i,j,dp[i][j]);
			}
			dp[i][j]=(dp[i][j]+1LL*dp[i-1][j]*(powk[j]-powkm[j]+mod)%mod*powkm[n-j])%mod;
		}
	}
	printf("%d\n",dp[n][n]);
}