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
const int maxn=1e5+7;
int ans[maxn];
int ti[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n;
	cin>>n;
	int cc=0;
	vi query(2*n);
	for(int i=0;i<2*n;i++)
	{
		string op;
		cin>>op;
		if(op[0]=='+')
		{
			cc++;
			query[i]=0;
		}
		else{
			int x;
			cin>>x;
			ti[x]=cc-1;
			query[i]=x;
		}
	}
	set<int>pos;
	for(int i=0;i<n;i++)
		pos.insert(i);
	for(int i=1;i<=n;i++)
	{
		auto it=pos.upper_bound(ti[i]);
		if(it==pos.begin())
		{
			cout<<"NO\n";
			return 0;
		}
		it--;
		ans[*it]=i;
		pos.erase(it);
	}
	cc=0;
	set<int> all;
	for(auto u:query)
	{
		if(!u)
		{
			all.insert(ans[cc]);
			cc++;
		}
		else{
			if(*all.begin()!=u)
			{
				cout<<"NO\n";
				return 0;
			}
			all.erase(all.begin());
		}

	}
	cout<<"YES\n";
	for(int i=0;i<n;i++) cout<<ans[i]<<" \n"[i==n-1];
}