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
int nxt[maxn][26];
int pre[maxn][26];
int dp1[maxn],dp2[maxn];
char s[maxn],t[maxn];
int main()
{
	scanf("%s%s",s+1,t+1);
	int lens=strlen(s+1),lent=strlen(t+1);
	int cur[26];
	memset(cur,-1,sizeof(cur));
	for(int i=lens;i>=0;i--)
	{
		for(int j=0;j<26;j++)
			nxt[i][j]=cur[j];
		if(i)
			cur[s[i]-'a']=i;
	}
	memset(cur,-1,sizeof(cur));
	for(int i=1;i<=lens+1;i++)
	{
		for(int j=0;j<26;j++)
			pre[i][j]=cur[j];
		if(i!=lens+1)
			cur[s[i]-'a']=i;
	}
	int pos=0;
	for(int i=1;i<=lent;i++)
	{
		dp1[i]=nxt[pos][t[i]-'a'];
		pos=nxt[pos][t[i]-'a'];
	}
	pos=lens+1;
	for(int i=lent;i>=1;i--)
	{
		dp2[i]=pre[pos][t[i]-'a'];
		pos=pre[pos][t[i]-'a'];
	}
	int ans=max(dp2[1]-1,lens-dp1[lent]);
	for(int i=1;i<=lent;i++)
	{
		ans=max(ans,dp2[i+1]-dp1[i]-1);
	}
	printf("%d\n",ans);
}