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
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
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
const int maxn=5e5+7;
vi G[maxn];
int nxt[maxn];
int sz[maxn];
pi ans[maxn];
void dfs(int u,int fa=-1)
{
	sz[u]=1;
	for(auto v:G[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
void solve(int u,int fa,int L,int R)
{
	if(G[u].size()==1&&fa!=-1) return;
	//dbg(u,fa,L,R);
	for(auto v:G[u])if(v!=fa)
	{
		ans[v]=make_pair(L,R-(sz[v]-1)*2+(G[v].size()-1));
		L++;
		solve(v,u,ans[v].second-(G[v].size()-1),R);
		R=ans[v].second-G[v].size();
		//dbg(u,v,L,R);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=1,u,v;i<n;i++)
	{
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	ans[1]=make_pair(1,2*n-(sz[1]-1)*2+G[1].size());
	solve(1,-1,2,2*n);
	for(int i=1;i<=n;i++) cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}