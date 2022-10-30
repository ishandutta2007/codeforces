#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
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
struct node{
	int mi[10],mi2[10];
	void clear(){
		memset(mi,0x3f,sizeof(mi));
		memset(mi2,0x3f,sizeof(mi2));
	}
};
#define lson o<<1
#define rson o<<1|1
#define Lson L,mid,lson
#define Rson mid+1,R,rson
int n,m;
const int maxn=2e5+7;
int a[maxn];
struct Seg{
	node seg[maxn<<2];
	inline node Merge(node a,node b)
	{
		node ret;
		for(int i=0;i<10;i++)
		{
			ret.mi[i]=min(a.mi[i],b.mi[i]);
			if(a.mi[i]<b.mi[i]) ret.mi2[i]=min(b.mi[i],a.mi2[i]);
			else if(a.mi[i]>b.mi[i]) ret.mi2[i]=min(a.mi[i],b.mi2[i]);
			else ret.mi2[i]=a.mi[i];
		}
		return ret;
	}
	inline void pushup(int o)
	{
		seg[o]=Merge(seg[lson],seg[rson]);
	}
	void update(int p,int flag,int L=1,int R=n,int o=1)
	{
		if(L==R)
		{
			seg[o].clear();
			if(flag){
				ll cur=1;
				for(int i=0;i<10;i++)
				{
					if(a[p]/cur%10!=0)
						seg[o].mi[i]=a[p];
					cur*=10;
				}
			}
			return;
		}
		int mid=L+R>>1;
		if(p<=mid) update(p,flag,Lson);
		else update(p,flag,Rson);
		pushup(o);
	}
	node query(int l,int r,int L=1,int R=n,int o=1)
	{
		if(l<=L&&r>=R)
			return seg[o];
		int mid=L+R>>1;
		node ret;
		ret.clear();
		if(l<=mid) ret=Merge(ret,query(l,r,Lson));
		if(r>mid) ret=Merge(ret,query(l,r,Rson));
		return ret;
	}
}tree;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		tree.update(i,1);
	while(m--)
	{
		int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			tree.update(l,0);
			a[l]=r;
			tree.update(l,1);
		}
		else{
			int ans=2*INF;
			node cur=tree.query(l,r);
			for(int i=0;i<10;i++)
			{
				if(cur.mi[i]==INF||cur.mi2[i]==INF) continue;
				ans=min(ans,cur.mi[i]+cur.mi2[i]);
			}
			if(ans==2*INF) puts("-1");
			else printf("%d\n",ans);
		}
	}
}