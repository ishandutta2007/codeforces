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
const int INF=0x3f3f3f3f;
const int maxn=5e5+7;
deque<int> q[maxn];
typedef unsigned long long ull;
map<ull,int> cnt;
ull val[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin>>n;
	vi a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	int p=0;
	cnt[0]++;
	vc<ull> pre(n+1);
	auto del=[&](int x){
		cnt[pre[p]]--;
		while(p<x)
		{
			p++;
			int v=a[p];
			q[v].pop_front();
			cnt[pre[p]]--;
		}
		cnt[pre[p]]++;
	};
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int v=a[i];
		if(q[v].size()==3)
		{
			int fr=q[v].front();
			del(fr);
		}
		if(q[v].size()==2)
			val[i]=-val[q[v][0]]-val[q[v][1]];
		else val[i]=rand_int(0LL,(ll)4e18);
		q[v].push_back(i);
		pre[i]=pre[i-1]+val[i];
		ans+=cnt[pre[i]];
		cnt[pre[i]]++;
		dbg(i,val[i],pre[i]);
		dbg(i,ans);
	}
	print(ans);
}