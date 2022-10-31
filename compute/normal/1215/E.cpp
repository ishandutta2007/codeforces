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
const int maxn=4e5+7;
int a[maxn];
int pre[maxn][21];
ll sum[21][21];
const int var=20;
ll dp[1<<var];
ll ans=0x3f3f3f3f3f3f3f3f;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int pp[21];
	memset(pp,0,sizeof(pp));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=20;j++)
		{
			pre[i][j]=pp[j];
			sum[a[i]][j]+=pre[i][j];
		}
		pp[a[i]]++;
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int S=0;S<(1<<var);S++)
	{
		for(int i=0;i<var;i++)
		{
			if(!(S>>i&1))
			{
				int nxt=(S|(1<<i));
				ll v=0;
				for(int j=0;j<var;j++)
				{
					if(!(nxt>>j&1))
						v+=sum[i+1][j+1];
				}
				dp[nxt]=min(dp[nxt],v+dp[S]);
			}
		}
	}
	printf("%lld\n",dp[(1<<var)-1]);
}