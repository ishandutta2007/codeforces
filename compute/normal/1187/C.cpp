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
const int maxn=1005;
int fa[maxn],sz[maxn];
void init()
{
	for(int i=0;i<maxn;i++) fa[i]=i,sz[i]=1;
}
int Find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
	x=Find(x);y=Find(y);
	fa[y]=x;
	sz[x]+=sz[y];
	sz[y]=sz[x];
}
struct seg{
	int l,r;
};
bool tag[maxn];
vector<seg> tot;
int ans[maxn];
int main()
{
	init();
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) ans[i]=1;
	for(int i=0;i<m;i++)
	{
		int tp,l,r;
		scanf("%d%d%d",&tp,&l,&r);
		if(tp)
		{
			for(int j=l;j<=r;j++)
			{
				if(j!=l)
					Union(j,j-1);
			}
		}
		else tot.push_back(seg {l,r});
	}
	bool ok=1;
	for(int i=0;i<tot.size();i++)
	{
		seg cur=tot[i];
		bool sss=0;
		for(int j=cur.l;j<cur.r;j++)
		{
			if(Find(j)!=Find(j+1))
			{
				sss=1;
				tag[j+1]=1;
				break;
			}
		}
		if(!sss) {
			ok=0;break;
		}
	}
	if(ok)
	{
		puts("YES");
		int val=1000;
		for(int i=1;i<=n;i++)
		{
			if(tag[i]) val--;
			else val++;
			printf("%d ",val);
		}
		puts("");
	}
	else puts("NO");
}