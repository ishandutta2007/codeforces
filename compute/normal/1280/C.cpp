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
typedef pair<int,int> PII;
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
struct Edge{
	int to,w;
};
struct E{
	int u,v,w;
};
const int maxn=2e5+7;
vc<Edge> G[maxn];
int sz[maxn],dep[maxn];
void dfs(int u,int fa=-1)
{
	sz[u]=1;
	for(auto e:G[u])
	{
		if(e.to==fa) continue;
		dep[e.to]=dep[u]+1;
		dfs(e.to,u);
		sz[u]+=sz[e.to];
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int k;
		cin>>k;
		vc<E> all;
		for(int i=0;i<=2*k;i++) G[i].clear();
		for(int i=1,u,v,w;i<2*k;i++)
		{
			cin>>u>>v>>w;
			G[u].push_back({v,w});
			G[v].push_back({u,w});
			all.push_back({u,v,w});
		}
		dep[1]=1;
		dfs(1);
		ll minans=0,mxans=0;
		for(auto e:all)
		{
			int u=e.u,v=e.v,w=e.w;
			if(dep[u]>dep[v]) swap(u,v);
			if(sz[v]&1)
				minans+=w;
			mxans+=1LL*w*min(sz[v],2*k-sz[v]);
		}
		cout<<minans<<" "<<mxans<<'\n';
	}
}