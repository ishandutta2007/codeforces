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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n;
	cin>>n;
	vc<string> s(n);
	for(int i=0;i<n;i++) cin>>s[i];
	vc<pi> p(n);
	for(int i=0;i<n;i++)
	{
		for(auto c:s[i])
		{
			if(c=='B') p[i].first++;
			else p[i].second++;
		}
	}
	auto getdis=[&](int c1,int c2,int y1,int y2){
		if(c1>=y1&&c2>=y2)
			return max(c1-y1,c2-y2);
		if(c1<=y1&&c2<=y2) return max(y1-c1,y2-c2);
		return abs(c1-y1)+abs(c2-y2);
	};
	auto getv=[&](int c1,int c2){
		int ret=0;
		for(int i=0;i<n;i++)
			ret=max(ret,getdis(c1,c2,p[i].first,p[i].second));
		return ret;
	};
	auto solve=[&](int x){
		int L=0,R=5e5+7;
		while(L<R)
		{
			int len=(R-L)/3;
			int l=L+len,r=R-len;
			int cl=getv(x,l),cr=getv(x,r);
			if(cl<cr) R=r-1;
			else L=l+1;
		}
		return make_pair(L,getv(x,L));
	};
	int L=0,R=5e5+7;
	while(L<R)
	{
		int len=(R-L)/3;
		int l=L+len,r=R-len;
		auto lp=solve(l),rp=solve(r);
		if(lp.second<rp.second)
			R=r-1;
		else L=l+1;
	}
	auto ans=solve(L);
	print(ans.second);
	string op;
	for(int i=0;i<L;i++) op+='B';
	for(int i=0;i<ans.first;i++) op+='N';
	cout<<op<<'\n';
}