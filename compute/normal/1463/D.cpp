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
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vi b(n);
		map<int,int> ext;
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
			ext[b[i]]=1;
		}
		set<int> st;
		for(int i=1;i<=2*n;i++)
			if(!ext.count(i)) st.insert(i);
		set<int> rt=st;
		int left=0;
		for(int i=0;i<n;i++)
		{
			auto it=st.lower_bound(b[i]);
			if(it==st.end()) break;
			st.erase(it);
			left++;
		}
		int right=0;
		for(int i=n-1;i>=0;i--)
		{
			auto it=rt.lower_bound(b[i]);
			if(it==rt.begin()) break;
			it--;
			rt.erase(it);
			right++;
		}
		dbg(left,right);
		int ans=0;
		for(int i=0;i<=n;i++)
		{
			if(left>=i&&right>=n-i) ans++;
		}
		print(ans);

	}
}