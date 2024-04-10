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
ll arr[maxn];
ll dp[maxn][3];
int main()
{
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++)
		scanf("%lld",&arr[i]);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=dp[i-1][0]>0?dp[i-1][0]+arr[i]:arr[i];
		dp[i][1]=max(dp[i-1][1]+arr[i]*x,dp[i-1][0]+arr[i]*x);
		dp[i][1]=max(dp[i-1][1]>0?dp[i-1][1]+arr[i]*x:arr[i]*x,dp[i-1][0]>0?dp[i-1][0]+arr[i]*x:arr[i]*x);
		dp[i][2]=max(dp[i-1][1]>0?dp[i-1][1]+arr[i]:arr[i],dp[i-1][2]>0?dp[i-1][2]+arr[i]:arr[i]);
		for(int j=0;j<3;j++) ans=max(ans,dp[i][j]);
	}
	printf("%lld\n",ans);
}