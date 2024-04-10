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
void solve()
{
	int n,l,r;
	cin>>n>>l>>r;
	vi cnt(n);
	for(int i=0,x;i<l;i++)
	{
		cin>>x;
		x--;
		cnt[x]++;
	}
	for(int i=0,x;i<r;i++)
	{
		cin>>x;
		x--;
		cnt[x]--;
	}
	int ans=0;
	vi L,R;
	for(int i=0;i<n;i++)
	{
		if(cnt[i]<0) R.push_back(-cnt[i]);
		else if(cnt[i]) L.push_back(cnt[i]);
	}
	int suml=accumulate(L.begin(),L.end(),0);
	int sumr=accumulate(R.begin(),R.end(),0);
	if(suml<sumr)
	{
		swap(suml,sumr);
		swap(L,R);
	}
	for(int i=0;i<L.size();i++)
	{
		while(L[i]>1&&suml>sumr)
		{
			suml-=2;
			L[i]-=2;
			ans++;
		}
	}
	//dbg(suml,sumr);
	ans+=suml-sumr;
	ans+=sumr;
	print(ans);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
		solve();
}