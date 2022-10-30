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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		int n,x,y;
		cin>>n>>x>>y;
		int d=y-x;
		vi ans(n,1e9);
		for(int i=1;i<=d;i++)
		{
			if(d%i==0)
			{
				vi cur;
				int cc=d/i+1;
				if(cc>n) continue;
				deque<int> q;
				for(int j=x;j<=y;j+=i) q.push_back(j);
				while(q.size()<n&&q.front()>i) q.push_front(q.front()-i);
				while(q.size()<n) q.push_back(q.back()+i);
				for(auto u:q) cur.push_back(u);
				if(cur[n-1]<ans[n-1]) ans=cur;
			}
		}
		print(ans);
	}
}