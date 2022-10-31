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
const int maxn=2e6+7;
int dp[maxn],f[maxn];
int main()
{
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		int cur=0;
		for(int j=i;j<s.length();j++)
		{
			if(cur>>(s[j]-'a')&1) break;
			cur|=1<<(s[j]-'a');
			dp[cur]=__builtin_popcount(cur);
		}
	}
	for(int i=0;i<(1<<20);i++) f[i]=dp[i];
	for(int j=0;j<20;j++)
	{
		for(int i=0;i<(1<<20);i++)
			if(i>>j&1) f[i]=max(f[i],f[i^(1<<j)]);
	}
	int ans=0;
	for(int i=0;i<(1<<20);i++)
		ans=max(ans,dp[i]+f[((1<<20)-1)^i]);
	cout<<ans<<endl;
}