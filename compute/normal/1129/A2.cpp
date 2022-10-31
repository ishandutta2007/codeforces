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
const int maxn=2e4+7;
struct Seg{
	int l,r;
	bool operator<(const Seg& a)const{
		if(a.l==l) return a.r<r;
		return a.l<l;
	}
}seg[maxn];
vector<int> candy[5005];
int ans[5005];
int Near[5005];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&seg[i].l,&seg[i].r);
		candy[seg[i].l].push_back(seg[i].r);
	}
	int ma=0;
	for(int i=1;i<=n;i++) 
	{
		ma=max(ma,(int)candy[i].size());
		int cur=0x3f3f3f3f;
		for(auto& p:candy[i]) cur=min(cur,p<i?p+n-i:p-i);
		Near[i]=cur;
		dbg(i);dbg(Near[i]);
	}
	for(int i=0;i<=n-1;i++)
	{
		ans[i+1]=0;
		for(int j=1;j<=n;j++)
		{
			if(candy[j].size())
			{
				ans[i+1]=max(ans[i+1],((int)candy[j].size()-1)*n+Near[j]+(j>i?(j-i-1):j+n-i-1));
			}
		}
	}
	for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ');

}