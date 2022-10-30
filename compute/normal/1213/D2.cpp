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
const int maxn=4e5+7;
const int INF=0x3f3f3f3f;
int arr[maxn];
vector<int> ans[maxn];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		int cnt=0;
		while(x)
		{
			ans[x].push_back(cnt);
			cnt++;
			x/=2;
		}
	}
	int op=INF;
	for(int i=1;i<=200000;i++)
	{
		if(ans[i].size()>=k)
		{
		//	if(ans[i*2].size()>=k||ans[i*2+1].size()>=k) continue;
			sort(ans[i].begin(),ans[i].end());
			int cur=0;
			for(int j=0;j<k;j++)
				cur+=ans[i][j];
			op=min(op,cur);
		}
	}
	printf("%d\n",op);
}