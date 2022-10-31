#include<bits/stdc++.h>
using namespace std;
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
const int maxn=5e3+7;
int arr[maxn];
int dp[maxn][maxn];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
	sort(arr+1,arr+n+1);
	int ans=0;
	for(int i=1,j=1;i<=n;i++)
	{
		for(int l=0;l<=k;l++) dp[i][l]=dp[i-1][l];
		while(arr[i]-arr[j]>5) j++;
		for(int l=1;l<=k;l++)
		{
			dp[i][l]=max(dp[i][l],dp[j-1][l-1]+i-j+1);
		}
	}
	printf("%d\n",dp[n][k]);
}