#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
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
ll rand_int(ll l, ll r) //[l, r]
{
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
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
typedef double ld;
const ld PI=3.141592653589;
struct P{
	ld x,y;
};
int n;
ll k;
vc<P> pt;
struct Bit{
	vi t;
	int sz;
	Bit(int n){
		sz=n+2;
		t=vi(sz);
	}
	void add(int x,int v)
	{
		x++;
		while(x<sz)
		{
			t[x]+=v;
			x+=x&-x;
		}
	}
	int query(int x)
	{
		x++;
		int ret=0;
		while(x)
		{
			ret+=t[x];
			x-=x&-x;
		}
		return ret;
	}
};
ll solve(ld x)
{
	ll ret=1LL*n*(n-1)/2;
	vc<P> a;
	for(auto p:pt)
	{
		ld dis=sqrt(p.x*p.x+p.y*p.y);
		if(dis>x) a.push_back(p);
	}
	vc<pair<ld,int>> all;
	int cc=1;
	vc<pi> id(a.size()+1);
	for(auto p:a)
	{
		ld dis=sqrt(p.x*p.x+p.y*p.y);
		ld ang=acos(x/dis);
		ld base=atan2(p.y,p.x);
		ld lw=base-ang,up=base+ang;
		if(lw<-PI) lw+=2*PI;
		if(up>PI) up-=2*PI;
		if(lw>up) swap(lw,up);
		all.emplace_back(lw,cc);
		all.emplace_back(up,-cc);
		cc++;
	}
	sort(all.begin(),all.end());
	for(int i=0;i<all.size();i++)
	{
		int cid=all[i].second;
		if(cid>0) id[cid].first=i;
		else id[-cid].second=i;
	}
	Bit T(all.size());
	for(auto u:all)
	{
		int cid=u.second;
		if(cid>0)
			T.add(id[cid].first,1);
		else{
			T.add(id[-cid].first,-1);
			ret-=T.query(id[-cid].second)-T.query(id[-cid].first);
		}
	}
	return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>n>>k;
	pt=vc<P>(n);
	for(int i=0;i<n;i++)
		cin>>pt[i].x>>pt[i].y;
	ld L=0,R=1e6;
	int T=60;
	while(T--)
	{
		ld mid=(L+R)/2;
		if(solve(mid)>=k)
			R=mid;
		else L=mid;
	}
	cout<<fixed<<setprecision(10)<<R<<'\n';
}