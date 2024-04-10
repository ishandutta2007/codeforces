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
struct Bit{
	vi t;
	int sz;
	Bit(int n){
		sz=n+2;
		t=vi(sz);
	}
	void add(int x){
		x++;
		while(x<sz)
		{
			t[x]++;
			x+=x&-x;
		}
	}
	int query(int x){
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
		int ans=n-1;
		vc<pi> sg(n);
		vi all;
		for(int i=0;i<n;i++)
		{
			cin>>sg[i].first>>sg[i].second;
			all.push_back(sg[i].first);
			all.push_back(sg[i].second);
		}
		mkuni(all);
		auto getid=[&](int x){
			return lower_bound(all.begin(),all.end(),x)-all.begin();
		};
		Bit T(all.size());
		sort(sg.begin(),sg.end());
		for(int i=0;i<sg.size();i++)
		{
			int c1,c2;
			c1=i-T.query(getid(sg[i].first)-1);
			c2=lower_bound(sg.begin()+i+1,sg.end(),sg[i],[&](const pi &x,const pi &y){
				return x.first<=y.second;
			})-sg.begin()-i-1;
			dbg(c1,c2);
			ans=min(ans,n-c1-c2-1);
			T.add(getid(sg[i].second));
		}
		print(ans);
	}
}