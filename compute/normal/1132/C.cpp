#include<bits/stdc++.h>
using namespace std;
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
const int maxn=5005;
int l[maxn],r[maxn];
int arr[maxn];
int cov[maxn];
int pre[maxn];
int pre2[maxn];
struct Seg{
	int l,r;
	bool operator<(const Seg&a)const{
		if(l==a.l)
			return r<a.r;
		return l<a.l;
	}
}seg[maxn];
int main()
{
	int n,q;
	int tot=0;
	scanf("%d%d",&n,&q);
	for(int i=0;i<q;i++)
	{
		scanf("%d%d",&seg[i].l,&seg[i].r);
		arr[seg[i].l]++;arr[seg[i].r+1]--;
	}
	for(int i=1;i<=n;i++)
		cov[i]=cov[i-1]+arr[i];
	for(int i=1;i<=n;i++)
	{
		if(cov[i]) tot++;
		pre[i]=pre[i-1];
		if(cov[i]==1)
			pre[i]++;
		pre2[i]=pre2[i-1];
		if(cov[i]==2)
			pre2[i]++;
		dbg(i);dbg(pre[i]);dbg(pre2[i]);
	}
	sort(seg,seg+q);
	int ans=0;
	for(int i=0;i<q;i++)
	{
		for(int j=i+1;j<q;j++)
		{
			int cur=tot;
			if(seg[j].l>seg[i].r)
				cur-=pre[seg[j].r]-pre[seg[j].l-1]+pre[seg[i].r]-pre[seg[i].l-1];
			else{
				if(seg[j].r>seg[i].r)
				{
					cur-=pre2[seg[i].r]-pre2[seg[j].l-1];
					cur-=pre[seg[j].l-1]-pre[seg[i].l-1]+pre[seg[j].r]-pre[seg[i].r];
				}
				else{
					cur-=pre2[seg[j].r]-pre2[seg[j].l-1];
					cur-=pre[seg[j].l-1]-pre[seg[i].l-1]+pre[seg[i].r]-pre[seg[j].r];
				}
			}
			ans=max(ans,cur);
			dbg(i);dbg(j);dbg(cur);
		}
	}
	printf("%d\n",ans);
}