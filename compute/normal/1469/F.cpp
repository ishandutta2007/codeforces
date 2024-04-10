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
const int maxn=1e6+7;
int n,k;
struct D{
	int st,ed;
	bool operator<(const D&a)const{
		return st>a.st;
	}
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>n>>k;
	vi l(n);
	for(int i=0;i<n;i++) cin>>l[i];
	sort(l.begin(),l.end(),greater<int>());
	auto check=[&](int x){
		dbg(x);
		priority_queue<D> q;
		q.push({0,0});
		ll cnt=1;
		auto add=[&](int d,int len){
			int tar=d+1+len;
			tar=min(tar,x);
			int st=d+2;
			dbg(st,tar);
			if(st>tar) return;
			cnt+=tar-st+1;
			q.push({st,tar});
		};
		for(auto u:l)
		{
			int c1=(u-1)/2,c2=u-1-c1;
			auto cur=q.top();q.pop();
			if(cur.st!=cur.ed) q.push({cur.st+1,cur.ed});
			cnt--;
			add(cur.st,c1);
			add(cur.st,c2);
			if(cnt>=k) return true;
		}
		return false;
	};
	int L=0,R=1e7,ans=-1;
	while(L<=R)
	{
		int mid=L+R>>1;
		if(check(mid))
		{
			ans=mid;
			R=mid-1;
		}
		else L=mid+1;
	}
	print(ans);
}