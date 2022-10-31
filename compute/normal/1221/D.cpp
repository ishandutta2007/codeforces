#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const ll INF=0x3f3f3f3f3f3f3f3f;
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
ll quick(ll a,ll b,ll mod)
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
ll inv(ll a,ll mod){return quick(a,mod-2,mod);}
const int maxn=3e5+7;
int a[maxn],b[maxn];
const int var=10;
ll dp[maxn][var];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) 
		{
			scanf("%d%d",&a[i],&b[i]);
			for(int j=0;j<var;j++)
				dp[i][j]=INF;
		}
		for(int j=0;j<var;j++) dp[1][j]=1LL*j*b[1];
		ll ans=INF;
		for(int i=2;i<=n;i++)
		{
			for(int j=0;j<var;j++)
			{
				for(int k=0;k<var;k++)
				{
					ll pre=a[i-1]+j,cur=a[i]+k;
					if(pre==cur) continue;
					dp[i][k]=min(dp[i][k],dp[i-1][j]+1LL*k*b[i]);
				}
			}
		}
		for(int j=0;j<var;j++)
			ans=min(ans,dp[n][j]);
		printf("%lld\n",ans);
	}
}