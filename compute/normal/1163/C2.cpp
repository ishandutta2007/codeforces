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
const ll INF=1LL<<61;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;

void modify(PII &x)
{
	if(!x.second) x.first=1;
	else if(!x.first)
		x.second=1;
	else{
		int gcd=__gcd(abs(x.first),abs(x.second));
		if(x.first<0)
			x.first*=-1,x.second*=-1;
		x.first/=gcd,x.second/=gcd;
	}
}
struct P{
	int x,y;
}pt[maxn];
struct node{
	ll a,b,c;
	bool operator<(const node&z)const{
		if(a==z.a)
		{
			if(b==z.b)
				return c<z.c;
			return b<z.b;
		}
		return a<z.a;
	}
};
node getnode(int i,int j)
{
	node ret;
	ret.a=pt[j].y-pt[i].y;
	ret.b=pt[i].x-pt[j].x;
	ret.c=-pt[i].x*pt[j].y+pt[j].x*pt[i].y;
	int gcd=__gcd(__gcd(abs(ret.a),abs(ret.b)),abs(ret.c));
	if(ret.a<0)
	{
		ret.a*=-1;
		ret.b*=-1;
		ret.c*=-1;
	}
	else if(ret.a==0)
	{
		if(ret.b<0) ret.b*=-1,ret.c*=-1;
	}
	ret.a/=gcd,ret.b/=gcd,ret.c/=gcd;
	return ret;
}
set<node> st;
map<PII,int> app;
int main()
{
	int n;
	scanf("%d",&n);
	ll ans=0;
	for(int i=0;i<n;i++) scanf("%d%d",&pt[i].x,&pt[i].y);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			PII v=make_pair(pt[j].y-pt[i].y,pt[j].x-pt[i].x);
			modify(v);
			node cur=getnode(i,j);
			dbg(i,j,cur.a,cur.b,cur.c);
			if(st.count(cur)) continue;
			ans+=st.size()-app[v];
			app[v]++;
			st.insert(cur);
			dbg(i,j,ans);
		}
	}
	printf("%lld\n",ans);
}