#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[33;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
#define int ll
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
using tp=pair<int,string>;
tp solve(string s,string t)
{
	if(t.length()==1) return {0,s};
	tp ret(0,"");
	for(int i=0;i<t.length();i++)
	{
		char cur=t[i];
		vi pos;
		for(int j=0;j<s.length();j++)
		{
			if(s[j]==cur)
				pos.push_back(j);
		}
		int ans1=0;
		for(int i=0;i<pos.size();i++)
			ans1+=abs(pos[i]-i);
		int ans2=0;
		for(int i=0;i<pos.size();i++)
			ans2+=int(s.length())-i-1-pos[pos.size()-i-1];
		string ns,nt;
		for(int j=0;j<s.length();j++)
		{
			if(s[j]!=cur) ns+=s[j];
		}
		for(int j=0;j<t.length();j++)
		{
			if(t[j]!=cur) nt+=t[j];
		}
		auto nxt=solve(ns,nt);
		string tar(pos.size(),cur);
		if(ans1>=ans2)
			nxt.second=tar+nxt.second;
		else{
			nxt.second+=tar;
		}
		nxt.first+=max(ans1,ans2);
		ret=max(ret,nxt);
	}
	return ret;
}
void solve()
{
	string s;
	cin>>s;
	string t="ANOT";
	auto ans=solve(s,t);
	cout<<ans.second<<'\n';
}
signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--) solve();
}