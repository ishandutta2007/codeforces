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
		vi a(n);vc<vi> pos(n+1);
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			pos[a[i]].push_back(i);
		}
		vi ans(n);
		if(pos[1].size()!=0)
		{
			ans[n-1]=1;
			//if(pos[1].size()>1||(pos[1][0]!=0&&pos[1][0]!=n-1));
			//else{
			vi L(n+1),R(n+1);
			stack<int> s;
			for(int i=0;i<n;i++)
			{
				while(s.size()&&a[s.top()]>a[i])
				{
					auto u=s.top();
					R[u]=i-1;
					s.pop();
				}
				s.push(i);
			}
			while(!s.empty())
			{
				R[s.top()]=n-1;
				s.pop();
			}
			for(int i=n-1;i>=0;i--)
			{
				while(s.size()&&a[s.top()]>a[i])
				{
					auto u=s.top();
					L[u]=i+1;
					s.pop();
				}
				s.push(i);
			}
			while(!s.empty())
			{
				L[s.top()]=0;
				s.pop();
			}
			vi len(n+1);
			for(int i=0;i<n;i++)
			{
				len[a[i]]=R[i]-L[i]+1;
			}
			for(int i=1;i<=n;++i)
			{
				if(len[i]==n-i+1)
					ans[n-i]=1;
				else break;
			}
			{
				set<int> ss;
				for(int i=0;i<n;i++)
					ss.insert(a[i]);
				if(ss.size()==n&&*ss.rbegin()==n) ans[0]=1;
			}
		}
		for(int i=0;i<n;i++) cout<<ans[i];
		cout<<'\n';
		}
	}