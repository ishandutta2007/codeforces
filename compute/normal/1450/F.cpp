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
		vi a(n),cnt(n+1);
		bool suc=1;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			cnt[a[i]]++;
			if(cnt[a[i]]*2>n+(n&1)) suc=0;
		}
		if(!suc) print(-1);
		else{
			vc<pi> all;
			all.emplace_back(a[0],-1);
			int ans=0;
			for(int i=1;i<n;i++)
			{
				if(a[i]==a[i-1])
				{
					all.back().second=a[i-1];
					all.emplace_back(a[i],-1);
				}
			}
			all.back().second=a[n-1];
			ans=int(all.size())-1;
			map<int,int> cc;
			int mx=0,tar=-1;
			for(auto u:all)
			{
				if(u.first==u.second)
				{
					cc[u.first]++;
                    if(mx<cc[u.first])
                    {
                        mx=cc[u.first];
                        tar=u.first;
                    }
					mx=max(mx,cc[u.first]);
				}
			}
            int one=0;
            for(auto u:all)
            {
                if(u.first==tar||u.second==tar)
                {
                    if(u.first!=u.second) one++;
                }
            }
			ans+=max(0,2*mx-int(all.size())+one-1);
			print(ans);
		}
	}
}