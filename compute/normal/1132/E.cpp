#include<bits/stdc++.h>
using namespace std;
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
const int L=840;
long long dp[10][8*L+7];
int main()
{
	long long w;
	memset(dp,-1,sizeof(dp));
	long long cnt[10];
	cin>>w;
	for(int i=1;i<=8;i++) cin>>cnt[i];
	dp[0][0]=0;
	for(int i=1;i<=8;i++)
	{
		int up=min(1LL*L/i,cnt[i]);
		for(int k=0;k<=8*L;k++) dp[i][k]=dp[i-1][k];
		for(int j=1;j<=up;j++)
		{
			for(int k=8*L;k>=i*j;k--)
			{
				if(dp[i-1][k-i*j]==-1) continue;
				dp[i][k]=max(dp[i][k],dp[i-1][k-i*j]+(cnt[i]-j)/(L/i));
			}
		}
	}
	long long ans=0;
	for(int k=0;k<=min(8LL*L,w);k++)
	{
		if(dp[8][k]==-1) continue;
		ans=max(ans,k+min((w-k)/L,dp[8][k])*L);
	}
	cout<<ans<<endl;
}