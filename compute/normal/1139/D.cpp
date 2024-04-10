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
const int maxn=1e5+7;
const int mod=1e9+7;
int mu[maxn];
vector<int> prime,factor[maxn];
int mp[maxn];
void db()
{
	mu[1]=1;
	for(int i=2;i<maxn;i++)
	{
		if(!mp[i])
		{
			mp[i]=i;
			prime.push_back(i);
			mu[i]=-1;
		}
		for(auto& p:prime)
		{
			if(p*i>=maxn) break;
			if(i%p==0)
			{
				mp[p*i]=p;
				mu[p*i]=0;
				break;
			}
			mp[p*i]=p;
			mu[p*i]=-mu[i];
		}
	}
	for(int i=1;i<maxn;i++)
	{
		for(int j=1;j*j<=i;j++)
		{
			if(i%j==0) 
			{
				factor[i].push_back(j);
				if(j*j!=i) factor[i].push_back(i/j);
			}
		}
	}
}
long long quick(long long a,long long b)
{
	long long ret=1;
	while(b)
	{
		if(b&1) ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
long long inv(long long a){return quick(a,mod-2);}
long long dp[maxn];
int main()
{
	db();
	int m;
	cin>>m;
	dp[1]=1;
	for(int i=2;i<=m;i++)
	{
		long long sum=0;
		int tot=0;
		dbg(i);
		for(auto& p:factor[i])
		{
			if(p==i) continue;
			int cnt=0;
			for(auto& j:factor[i/p])
			{
				cnt+=mu[j]*(m/p/j);
			}
			dbg(p);
			dbg(cnt);
			if(p==1) tot=cnt;
			sum=(sum+dp[p]*cnt%mod)%mod;
		}
		dbg(m-tot);
		sum=(sum+m-tot)%mod;
		dp[i]=(sum*inv(m))%mod*m%mod*inv(m-(m/i))%mod;
		dbg(dp[i]);
	}
	long long ans=0;
	for(int i=1;i<=m;i++) ans=(ans+dp[i])%mod;
	ans=(ans+m-1)%mod;
	ans=(ans*inv(m))%mod;
	printf("%lld\n",ans);
}