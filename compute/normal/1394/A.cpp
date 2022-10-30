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
	int n,d,m;
	cin>>n>>d>>m;
	vi a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	vi bg,sm;
	for(int i=0;i<n;i++)
	{
		if(a[i]<=m) sm.push_back(a[i]);
		else bg.push_back(a[i]);
	}
	reverse(sm.begin(),sm.end());
	vc<ll> pre(sm.size());
	if(sm.size())
		pre[0]=sm[0];
	for(int i=1;i<sm.size();i++) pre[i]=pre[i-1]+sm[i];
	ll ans=0;
	ll cur=0;
	reverse(bg.begin(),bg.end());
	for(int i=0;i<=bg.size();i++)
	{
		if((i-1)*d+i>n) break;
		ll rem=0;
		int smtar=(int)sm.size()-max(0,(i-1)*d+i-(int)bg.size());
		smtar=max(0,smtar);
		dbg(i,cur,smtar);
		if(smtar) rem=pre[smtar-1];
		ans=max(ans,cur+rem);
		if(i<bg.size())
			cur+=bg[i];
	}
	print(ans);
}