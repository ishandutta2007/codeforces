#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
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
const int mod=998244353;
const int INF=0x3f3f3f3f;
ll quick(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll inv(ll a){return quick(a,mod-2);}
const int maxn=1e5+7;
int dp[1<<20];
int w[21][21];
int main()
{
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<s.length();i++)
	{
		w[s[i]-'a'][s[i-1]-'a']++;
		w[s[i-1]-'a'][s[i]-'a']++;
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int S=1;S<(1<<m);S++)
	{
		for(int i=0;(1<<i)<=S;i++)
			if(S>>i&1)
				dp[S]=min(dp[S],dp[S^(1<<i)]);
		for(int i=0;(1<<i)<=S;i++)
		{
			if(S>>i&1)
			{
				for(int j=0;j<m;j++)
				{
					if(!(S>>j&1))
						dp[S]+=w[i][j];
				}
			}
		}
	}
	cout<<dp[(1<<m)-1]<<endl;

}