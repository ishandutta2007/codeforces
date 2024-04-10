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
const int maxn=2e5+7;
int arr[maxn];
ll delta[maxn];
ll ans[maxn];
vector<PII> query[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&arr[i]);
		if(i!=1)
		{
			if(arr[i]==arr[i-1]) continue;
			query[arr[i]].push_back(make_pair(arr[i-1],abs(arr[i]-arr[i-1])));
			query[arr[i-1]].push_back(make_pair(arr[i],abs(arr[i]-arr[i-1])));
			ans[1]+=abs(arr[i]-arr[i-1]);
			delta[min(arr[i-1],arr[i])]--;
			delta[max(arr[i-1],arr[i])]++;
		}
	}
	ll cur=ans[1];
	cur+=delta[1];
	for(int i=2;i<=n;i++)
	{
		cur+=delta[i];
		ll nxt=cur;
		dbg(i,cur);
		for(auto u:query[i])
		{
			nxt-=u.second;
			nxt+=u.first;
			dbg(u.first,u.second,nxt);
		}
		ans[i]=nxt;
	}
	for(int i=1;i<=n;i++)
		printf("%lld%c",ans[i],i==n?'\n':' ');
}