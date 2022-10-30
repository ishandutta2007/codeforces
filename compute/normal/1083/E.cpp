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
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
        print(v[i],i==(int)(v.size())-1?suc:2);
}
const int INF=0x3f3f3f3f;
const int maxn=1e6+7;
struct L{
	ll a,b;
	inline ll get(ll x)//ax+b
	{return a*x+b;}
};
inline bool down(L a,L b, L c)
{
	return (__int128)(a.a-b.a)*(c.b-b.b)>=(__int128)(b.a-c.a)*(b.b-a.b);
}
struct ConvexHull{
	L dq[maxn];
	int sz;
	void clear(){sz=0;}
	void push(L x)
	{
		//while(sz>=2&&down(x,dq[sz],dq[sz-1])) sz--;//x.a
		while(sz>=2&&down(dq[sz-1],dq[sz],x)) sz--;//x.a
		dq[++sz]=x;
	}
	ll get(ll x)
	{
		ll L=1,R=sz,ret=-1;
		while(L<=R)
		{
			int mid=L+R>>1;
			if(mid==1||dq[mid].get(x)>=dq[mid-1].get(x))
			{
				ret=mid;
				L=mid+1;
			}
			else R=mid-1;
		}
		return dq[ret].get(x);
	}
}q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	ll ans=0;
	using tp=tuple<ll,ll,ll>;
	vc<tp> all;
	q.push(L{0,0});
	for(int i=0;i<n;i++)
	{
		ll x,y,a;
		cin>>x>>y>>a;
		all.emplace_back(x,y,a);
	}
	sort(all.begin(),all.end());
	for(int i=0;i<n;i++)
	{
		ll x,y,a;
		tie(x,y,a)=all[i];
		ll cur=x*y-a;
		if(!i) {
			q.push(L{-x,cur});
		}
		else{
			cur+=q.get(y);
			q.push(L{-x,cur});
		}
		ans=max(ans,cur);
	}
	print(ans);
}