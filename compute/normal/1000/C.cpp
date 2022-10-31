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
const int maxn=2e5+7;
struct Seg{
	ll l,r;
}seg[maxn];
vector<ll> all;
int getid(ll x)
{
	return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
}
int tree[maxn*2];
void add(int x,int val)
{
	while(x<maxn*2)
	{
		tree[x]+=val;
		x+=x&-x;
	}
}
int sum(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=tree[x];
		x-=x&-x;
	}
	return ret;
}
ll ans[maxn*2];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld",&seg[i].l,&seg[i].r);
		all.push_back(seg[i].l);
		all.push_back(seg[i].r+1);
	}
	sort(all.begin(),all.end());
	all.erase(unique(all.begin(),all.end()),all.end());
	for(int i=0;i<n;i++)
	{
		add(getid(seg[i].l),1);
		add(getid(seg[i].r+1),-1);
	}
	for(int i=1;i<all.size();i++)
	{
		ans[sum(i)]+=all[i]-all[i-1];
	}
	for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
	puts("");
}