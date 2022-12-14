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
const int maxn=3e5+7;
int tree[maxn];
void add(int x)
{
	x++;
	while(x<maxn)
	{
		tree[x]++;
		x+=x&-x;
	}
}
int query(int x)
{
	x++;
	int ret=0;
	while(x)
	{
		ret+=tree[x];
		x-=x&-x;
	}
	return ret;
}
int dis[30];
void solve(int t,vi a)
{
	if(t<0||!a.size()) return;
	vi l,r;
	vi cnt(2);
	int n=a.size();
	for(int j=0;j<n;j++)
	{
		if(a[j]>>t&1)
		{
			dis[t]+=cnt[0];
			r.push_back(a[j]);
		}
		else {
			dis[t]-=cnt[1];
			l.push_back(a[j]);
		}
		cnt[a[j]>>t&1]++;
	}
	solve(t-1,l);
	solve(t-1,r);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int x=0;
	solve(30,a);
	for(int j=0;j<30;j++)if(dis[j]<0) x+=1<<j;
	for(int i=0;i<n;i++) a[i]^=x;
	vi b=a;
	mkuni(b);
	auto getid=[&](int x){
		return lower_bound(b.begin(),b.end(),x)-b.begin();
	};
	ll ans=0;
	int cur=0;
	for(auto u:a)
	{
		int id=getid(u);
		ans+=cur-query(id);
		cur++;
		add(id);
	}
	cout<<ans<<" "<<x<<'\n';
}