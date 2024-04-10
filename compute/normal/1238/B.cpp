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
const int maxn=1e5+7;
int a[maxn];
vector<PII> all;
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,r;
		scanf("%d%d",&n,&r);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		a[n]=-1;
		int ans=0;
		int d=0;
		for(int i=n-1;i>=0;i--)
		{
			if(a[i]==a[i+1]) continue;
			if(a[i]-d<=0) break;
			ans++;
			d+=r;
		}
		printf("%d\n",ans);
	}
}