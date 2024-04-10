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
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='0') s[i]='1';
			else s[i]='0';
		}
		int t=min(k,25);
		int d=k-t;
		map<int,int> ext;
		vi pre(n);
		for(int i=0;i<n;i++)
		{
			pre[i]=s[i]=='1';
			if(i) pre[i]+=pre[i-1];
		}
		int cur=0;
		const int mx=1<<t;
		for(int i=0;i<t;i++) cur=cur*2+s[i]-'0';
		auto getv=[&](int x){
			return x>=0?pre[x]:0;
		};
		for(int i=t;i<=n;i++)
		{
			if(getv(i-t-1)-getv(i-t-d-1));
			else if(i>=k)
			{
				dbg(i,cur);
				ext[cur]=1;
			}
			if(i<n)
				cur=cur*2+s[i]-'0';
			cur%=mx;
		}
		int ans=0;
		while(ext.count(ans)) ans++;
		string op;
		while(ans)
		{
			op+=char('0'+ans%2);
			ans/=2;
		}
		if(op.length()>k)
		{
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		while(op.size()<k) op+='0';
		reverse(op.begin(),op.end());
		cout<<op<<'\n';

	}
}