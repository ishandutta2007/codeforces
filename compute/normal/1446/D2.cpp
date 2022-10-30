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
	int n;
	cin>>n;
	vi a(n);
	vc<vi> pos(n+1);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		pos[a[i]].push_back(i+1);
	}
	int ans=0;
	int mx=0,idx=-1;
	for(int i=1;i<=n;i++)
	{
		if(mx<pos[i].size())
		{
			mx=pos[i].size();
			idx=i;
		}
	}
	int x=idx;
	auto lwb=[&](int t){
		int p=lower_bound(pos[x].begin(),pos[x].end(),t)-pos[x].begin();
		return p;
	};
	for(int i=1;i<=n;i++)
	{
		if(x==i) continue;
		vi cur=pos[i];
		{
			int need=0,cp=0;
			for(int j=0;j<pos[i].size();j++)
			{
				int p=pos[i][j];
				int nx=j+1<pos[i].size()?pos[i][j+1]:n+1;
				if(!need)
				{
					cp=lwb(p);
					need=1;
				}
				need++;
				while(need&&cp<pos[x].size())
				{
					int tar=pos[x][cp];
					if(tar>=nx) break;
					cur.push_back(tar);
					need--;
					cp++;
				}
			}
			need=0,cp=pos[x].size()-1;
			for(int j=(int)pos[i].size()-1;j>=0;j--)
			{
				int p=pos[i][j];
				int nx=j?pos[i][j-1]:0;
				if(!need)
				{
					cp=lwb(p)-1;
					need=1;
				}
				need++;
				while(need&&cp>=0)
				{
					int tar=pos[x][cp];
					if(tar<=nx) break;
					cur.push_back(tar);
					need--;
					cp--;
				}
			}
		}
		mkuni(cur);
		dbg(i);
		dbg(cur);
		map<int,int> lst;
		int pre=0;
		lst[0]=0;
		for(int t=0;t<cur.size();t++)
		{
			int u=cur[t];
			if(a[u-1]==x) pre++;
			else pre--;
			int nxt=(t+1==cur.size()?n+1:cur[t+1]);
			if(lst.count(pre))
				ans=max(ans,nxt-lst[pre]-1);
			else lst[pre]=u;
		}
		dbg(ans);
	}
	print(ans);

}