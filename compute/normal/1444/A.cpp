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
		ll p,q;
		cin>>p>>q;
		vc<pi> all;
		for(int i=2;i*i<=q;i++)
		{
			if(q%i==0)
			{
				int cc=0;
				while(q%i==0)
				{
					cc++;
					q/=i;
				}
				all.emplace_back(i,cc);
			}
		}
		if(q!=1)
			all.emplace_back(q,1);
		sort(all.begin(),all.end());
		bool suc=0;
		for(auto u:all)
		{
			int cc=0;
			int cur=u.first;
			ll tmp=p;
			while(tmp%cur==0)
			{
				tmp/=cur;
				cc++;
			}
			if(cc<u.second) suc=1;
		}
		if(suc) print(p);
		else{
			ll ans=1;
			for(auto tar:all)
			{
				int tcnt=tar.second;
				int cur=tar.first;
				int cc=0;
				ll tmp=p;
				while(tmp%cur==0)
				{
					tmp/=cur;
					cc++;
				}
				tmp=p;
				while(cc>=tcnt)
				{
					tmp/=cur;
					cc--;
				}
				ans=max(ans,tmp);
			}
			print(ans);
		}

	}
}