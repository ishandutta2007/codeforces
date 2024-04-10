#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
const int maxn=2e5+7;
vector<int> all;
int dp[maxn];
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		all.clear();
		int h,n;
		cin>>h>>n;
		dp[0]=0;
		for(int i=0,tmp;i<n;i++)
		{
			scanf("%d",&tmp);
			all.push_back(tmp);
		}
		all.push_back(0);
		for(int i=1;i<=n;i++)
		{
			if(i==n)
			{
				dp[i]=dp[i-1];
				if(all[i]==all[i-1]-1&&i>1) dp[i]=min(dp[i-2],dp[i]);
				dbg(i,dp[i]);
				continue;
			}
			if(all[i]==all[i-1]-1&&i>1) dp[i]=min(dp[i-2],dp[i-1]+1);
			else dp[i]=dp[i-1]+1;
			dbg(i,dp[i]);
		}
		if(n==1) dp[1]=0;
		cout<<dp[n]<<endl;
	}
}