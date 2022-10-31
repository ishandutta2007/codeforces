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
const int maxn=1e5+7;
ll pre[maxn];
int arr[maxn];
map<int,int> vis;
int main()
{
	int n,M;
	scanf("%d%d",&n,&M);
	arr[n+1]=M;
	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1];
		scanf("%d",&arr[i]);
		vis[arr[i]]=1;
		if(i&1) pre[i]+=arr[i]-arr[i-1];
	}
	ll tot=pre[n];
	if((n+1)&1) tot+=arr[n+1]-arr[n];
	ll ans=tot;
	for(int i=1;i<=n;i++)
	{
		ll nxt;
		if(arr[i]!=1&&!vis[arr[i]-1])
		{
			if(i&1)
				nxt=pre[i]-1+(M-arr[i]-(tot-pre[i]));
			else nxt=pre[i]+(M-arr[i]-(tot-pre[i]));
			ans=max(ans,nxt);
		}
		if(arr[i]!=M-1&&!vis[arr[i]+1])
		{
			if(i&1)
				nxt=pre[i]-1+(M-arr[i]-tot+pre[i]);
			else nxt=pre[i]+(M-arr[i]-tot+pre[i]);
			ans=max(ans,nxt);
		}
	}
	printf("%lld\n",ans);

}