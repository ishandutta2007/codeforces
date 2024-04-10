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
const int maxn=3e5+7;
int arr[maxn];
int dp[maxn][21];
int las[maxn][21];
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(int j=0;j<21;j++) las[n][j]=n;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<21;j++)
		{
			if(arr[i]&(1<<j))
				las[i][j]=i;
			else las[i][j]=las[i+1][j];
		}
	}
	for(int i=0;i<21;i++) dp[n][i]=n;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<21;j++)
		{
			dp[i][j]=n;
			for(int k=0;k<21;k++)
			{
				if(arr[i]&(1<<k))
				{
					dp[i][j]=min(dp[i][j],dp[las[i+1][k]][j]);
					dp[i][k]=i;
				}
			}
		}
	}
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		l--,r--;
		bool ok=0;
		for(int i=0;i<21;i++)
		{
			if((arr[r]&(1<<i))&&dp[l][i]<=r)
			{
				ok=1;break;
			}
		}
		if(ok) puts("Shi");
		else puts("Fou");
	}
}