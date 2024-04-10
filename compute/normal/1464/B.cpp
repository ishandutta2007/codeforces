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
int x,y;
int getid(char c)
{
	if(c=='0') return 0;
	else if(c=='1') return 1;
	return 2;
}
ll solve(string s)
{
	int n=s.length();
	vi pos;
	for(int i=0;i<n;i++) if(s[i]=='?') pos.push_back(i);
	vc<vi> pre(n,vi(3));
	for(int i=0;i<n;i++)
	{
		pre[i][getid(s[i])]=1;
		if(i)
		for(int j=0;j<3;j++) pre[i][j]+=pre[i-1][j];
	}
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0'||s[i]=='?') ret+=1LL*pre[i][1]*y;
		else if(s[i]=='1') ret+=1LL*(pre[i][0]+pre[i][2])*x;
	}
	ll ans=ret;
	dbg(ret);
	for(auto p:pos)
	{
		ret-=1LL*(pre[p][1]+pre[p][2]-1)*y;
		ret-=1LL*(pre[n-1][1]-pre[p][1])*x;
		ret+=1LL*pre[p][0]*x;
		ret+=1LL*(pre[n-1][0]-pre[p][0]+pre[n-1][2]-pre[p][2])*y;
		dbg(p,ret);
		ans=min(ans,ret);
	}
	dbg(ans);
	return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	string s;
	cin>>s;
	cin>>x>>y;
	ll ans=solve(s);
	reverse(s.begin(),s.end());
	swap(x,y);
	ans=min(ans,solve(s));
	print(ans);
}