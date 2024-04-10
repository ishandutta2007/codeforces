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
struct Seg{
	int l,r;
}seg[305];
int arr[maxn];
int le[maxn],ri[maxn];
int ans[maxn];
int cnt[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
	for(int i=1,l,r;i<=m;i++)
		scanf("%d%d",&seg[i].l,&seg[i].r);
	int mn=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		ans[i]=mn;
		for(int j=1;j<=m;j++)
		{
			if(seg[j].r==i)
			{
				for(int k=seg[j].l;k<=seg[j].r;k++)
				{
					cnt[k]++;
					mn=min(mn,arr[k]-cnt[k]);
				}
			}
		}
		mn=min(mn,arr[i]);
	}
	mn=0x3f3f3f3f;
	memset(cnt,0,sizeof(cnt));
	for(int i=n;i>=1;i--)
	{
		ans[i]=min(ans[i],mn);
		for(int j=1;j<=m;j++)
		{
			if(seg[j].l==i)
			{
				for(int k=seg[j].l;k<=seg[j].r;k++)
				{
					cnt[k]++;
					mn=min(mn,arr[k]-cnt[k]);
				}
			}
		}
		mn=min(mn,arr[i]);
	}
	int op=0;
	for(int i=1;i<=n;i++)
	{
		op=max(arr[i]-ans[i],op);
	}
	vector<int> res;
	for(int i=1;i<=n;i++)
	{
		if(arr[i]-ans[i]==op)
		{
			for(int j=1;j<=m;j++)
			{
				if(seg[j].l>i||seg[j].r<i) res.push_back(j);
			}
			break;
		}
	}
	printf("%d\n",op);
	printf("%d\n",(int)res.size());
	for(auto& p:res) printf("%d ",p);
	puts("");
}