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
ll s[maxn];
ll ans[maxn];
ll sum[maxn<<2];
int n;
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
void update(int p,int val,int L=0,int R=n,int o=1)
{
	if(L==R)
	{
		sum[o]+=val;
		return;
	}
	int mid=L+R>>1;
	if(p<=mid) update(p,val,Lson);
	else update(p,val,Rson);
	sum[o]=sum[lson]+sum[rson];
}
set<int> st;
int query(ll tar,int L=0,int R=n,int o=1)
{
	if(L==R)
		return L;
	int mid=L+R>>1;
	if(tar<=sum[lson])
		return query(tar,Lson);
	else return query(tar-sum[lson],Rson);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&s[i]);
	for(int i=0;i<=n;i++)
	{
		update(i,i);
		st.insert(i);
	}
	for(int i=n;i>=1;i--)
	{
		ans[i]=*st.upper_bound(query(s[i]));
		update(ans[i],-ans[i]);
		st.erase(ans[i]);
	}
	for(int i=1;i<=n;i++)
		printf("%lld%c",ans[i],i==n?'\n':' ');
}