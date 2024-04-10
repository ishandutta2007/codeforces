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
#define Lson L,mid,o<<1
#define Rson mid+1,R,o<<1|1
const int maxn=2e5+7;
int n,q;
namespace Sgt{
	struct seg{
		int a,b,c,d,e,lz;
	}sgt[maxn*4];
	
	void init()
	{
		memset(sgt,0,sizeof(sgt));
	}

	seg merge(seg x,seg y)
	{
		seg ret;
		ret.a=max(x.a,y.a);
		ret.b=max(max(x.b,y.b),x.a-2*y.d);
		ret.c=max(max(x.c,y.c),max(x.a+y.e,x.b+y.a));
		ret.d=min(x.d,y.d);
		ret.e=max(max(x.e,y.e),-2*x.d+y.a);
		ret.lz=0;
		return ret;
	}

	void pushup(int o)
	{
		sgt[o]=merge(sgt[lson],sgt[rson]);
	}
	void pushdown(int o)
	{
		if(sgt[o].lz)
		{
			sgt[lson].a+=sgt[o].lz;
			sgt[lson].b-=sgt[o].lz;
			sgt[lson].d+=sgt[o].lz;
			sgt[lson].e-=sgt[o].lz;
			sgt[lson].lz+=sgt[o].lz;
			sgt[rson].a+=sgt[o].lz;
			sgt[rson].b-=sgt[o].lz;
			sgt[rson].d+=sgt[o].lz;
			sgt[rson].e-=sgt[o].lz;
			sgt[rson].lz+=sgt[o].lz;
			sgt[o].lz=0;
		}
	}

	void update(int l,int r,int val,int L=1,int R=n,int o=1)
	{
		if(l<=L&&r>=R)
		{
			sgt[o].a+=val;
			sgt[o].b-=val;
			sgt[o].d+=val;
			sgt[o].e-=val;
			sgt[o].lz+=val;
			return;
		}
		pushdown(o);
		int mid=L+R>>1;
		if(l<=mid) update(l,r,val,Lson);
		if(r>mid) update(l,r,val,Rson);
		pushup(o);
		dbg(L,R,sgt[o].a,sgt[o].b,sgt[o].c,sgt[o].d,sgt[o].e);
	}

};
int main()
{
	cin>>n>>q;
	n=(n-1)*2;
	string s;
	cin>>s;
	Sgt::init();
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(') Sgt::update(i+1,n,1);
		else Sgt::update(i+1,n,-1);
	}
	cout<<Sgt::sgt[1].c<<endl;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		if(l>r) swap(l,r);
		if(s[l-1]!=s[r-1])
		{
			if(s[l-1]=='(') Sgt::update(l,r-1,-2);
			else Sgt::update(l,r-1,2);
			swap(s[l-1],s[r-1]);
		}
		cout<<Sgt::sgt[1].c<<endl;
	}

}