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
int t[maxn];
int ans[maxn];
int sum[605];
#define lson o<<1
#define rson o<<1|1
#define Lson l,mid,lson
#define Rson mid+1,r,rson
int n,m;
int tree[605];
void addt(int x)
{
	while(x<105)
	{
		tree[x]++;
		x+=x&-x;
	}
}
int qq(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=tree[x];
		x-=x&-x;
	}
	return ret;
}
void pushup(int o)
{
	sum[o]=sum[lson]+sum[rson];
}
void add(int p,int l=1,int r=100,int o=1)
{
	if(l==r)
	{
		sum[o]+=l;
		return;
	}
	int mid=l+r>>1;
	if(p<=mid) add(p,Lson);
	else add(p,Rson);
	pushup(o);
}
int query(int k,int l=1,int r=100,int o=1)
{
	if(l==r)
		return k/l;
	int mid=l+r>>1;
	if(sum[lson]>=k)
		return query(k,Lson);
	return query(k-sum[lson],Rson)+qq(mid)-qq(l-1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&t[i]);
	for(int i=0;i<n;i++)
	{
		printf("%d%c",sum[1]>m-t[i]?i-query(m-t[i]):0,i==n-1?'\n':' ');
		add(t[i]);
		addt(t[i]);
	}

}