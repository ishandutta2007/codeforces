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
const int maxn=3e5+7;
vi G[maxn];
int main()
{
	int n;
	cin>>n;
	vi dp(n,1e9);
	vi h(n);
	for(int i=0;i<n;i++)
		cin>>h[i];
	stack<int> st;
	for(int i=0;i<n;i++)
	{
		while(st.size()&&h[i]<h[st.top()])
			st.pop();
		if(st.size()) G[i].push_back(st.top());
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i=0;i<n;i++)
	{
		while(st.size()&&h[i]>h[st.top()])
			st.pop();
		if(st.size()) G[i].push_back(st.top());
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i=n-1;i>=0;i--)
	{
		while(st.size()&&h[i]<h[st.top()])
			st.pop();
		if(st.size()) G[st.top()].push_back(i);
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i=n-1;i>=0;i--)
	{
		while(st.size()&&h[i]>h[st.top()])
			st.pop();
		if(st.size()) G[st.top()].push_back(i);
		st.push(i);
	}
	dp[0]=0;
	for(int i=1;i<n;i++)
	{
		for(auto v:G[i])
		{
			dp[i]=min(dp[i],dp[v]+1);
		}
	}
	print(dp[n-1]);
}