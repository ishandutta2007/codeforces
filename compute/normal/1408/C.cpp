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
		int n,l;
		cin>>n>>l;
		vi a(n+2);
		for(int i=1;i<=n;i++) cin>>a[i];
		a[0]=0;a[n+1]=l;
		double ans=-1,L=0,R=1e9;
		double tt=100;
		while(tt--)
		{
			double mid=(L+R)/2;
			double lpos=0,rpos=l;
			double t=0;
			for(int i=1;i<=n+1;i++)
			{
				double d=a[i]-lpos;
				double ct=d/i;
				if(ct+t<=mid)
				{
					t+=ct;
					lpos=a[i];
				}
				else {
					lpos+=(mid-t)*i;
					break;
				}
			}
			t=0;
			for(int i=n;i>=0;i--)
			{
				double d=rpos-a[i];
				double ct=d/(n+1-i);
				if(ct+t<=mid)
				{
					t+=ct;
					rpos=a[i];
				}
				else{
					rpos-=(mid-t)*(n+1-i);
					break;
				}
			}
			//dbg(L,R,mid,lpos,rpos);
			if(lpos>=rpos)
			{
				ans=mid;
				R=mid;
			}
			else L=mid;
		}
		cout<<fixed<<setprecision(10)<<ans<<'\n';
	}
}