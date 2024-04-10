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
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
const int maxn=3e5+7;
int mx[maxn<<2];
int n;
void pushup(int o)
{
	mx[o]=max(mx[lson],mx[rson]);
}
void update(int p,int val,int L=1,int R=n,int o=1)
{
	if(L==R)
	{
		mx[o]=val;
		return ;
	}
	int mid=L+R>>1;
	if(p<=mid) update(p,val,Lson);
	else update(p,val,Rson);
	pushup(o);
}
int query(int l,int r,int L=1,int R=n,int o=1)
{
	if(l<=L&&r>=R)
		return mx[o];
	int mid=L+R>>1;
	int ret=0;
	if(l<=mid)
		ret=max(ret,query(l,r,Lson));
	if(r>mid) ret=max(ret,query(l,r,Rson));
	return ret;
}
vector<int> pos[maxn];
int arr[maxn],brr[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0;i<=n;i++) pos[i].clear();
		for(int i=0;i<=4*n;i++)
			mx[i]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&arr[i]);
			pos[arr[i]].push_back(i);
			update(i,arr[i]);
		}
		for(int i=1;i<=n;i++)
			scanf("%d",&brr[i]);
		int dx=0;
		bool ok=1;
		for(int i=n;i>=1;i--)
		{
			while(!arr[i+dx]) dx--;
			if(brr[i]==arr[i+dx]) 
			{
				pos[brr[i]].pop_back();
				continue;
			}
			else{
				if(!pos[brr[i]].size())
				{
					ok=0;
					break;
				}
				if(query(pos[brr[i]].back(),i+dx)!=brr[i])
				{
					ok=0;
					break;
				}
				else{
					dx++;
					update(pos[brr[i]].back(),0);
					arr[pos[brr[i]].back()]=0;
					pos[brr[i]].pop_back();
				}
			}
		}
		puts(ok?"YES":"NO");
	}
}