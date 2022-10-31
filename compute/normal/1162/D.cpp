#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int maxn=2e5+7;
struct Seg{
	int l,r;
	bool operator<(const Seg& b)const{
		if(l==b.l) return r<b.r;
		return l<b.l;
	}
}seg[maxn];
map<pair<int,int> ,int> ext;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0,l,r;i<m;i++)
	{
		scanf("%d%d",&l,&r);
		l--,r--;
		ext[make_pair(l,r)]=1;
		ext[make_pair(r,l)]=1;
		seg[i].l=l,seg[i].r=r;
	}
	bool ok=0;
	sort(seg,seg+m);
	for(int i=1;i<n;i++)
	{
		bool bk=0;
		if(n%i!=0) continue;
		for(int j=0;j<m;j++)
		{
			if(!ext.count(make_pair((seg[j].l+i)%n,(seg[j].r+i)%n))&&!ext.count(make_pair((seg[j].l+i)%n,(seg[j].r+i)%n)))
			{
				bk=1;
				break;
			}
		}
		if(!bk)
		{
			ok=1;break;
		}
	}
	if(ok)
		puts("Yes");
	else puts("No");
}