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
const int maxn=1e5+7;
vi G[maxn];
int sz[maxn],maxson[maxn],rt;
int n;
void getrt(int u,int fa)
{
	sz[u]=1;
	maxson[u]=0;
	for(auto v:G[u])if(v!=fa)
	{
		getrt(v,u);
		sz[u]+=sz[v];
		maxson[u]=max(maxson[u],sz[v]);
	}
	maxson[u]=max(maxson[u],n-sz[u]);
	if(maxson[rt]>maxson[u])
		rt=u;
}
pi dfs(int u,int fa=-1)
{
	for(auto v:G[u])if(v!=fa)
	{
		return dfs(v,u);
	}
	return make_pair(fa,u);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		maxson[rt=0]=n+1;
		for(int i=0;i<=n;i++) G[i].clear();
		for(int i=1,u,v;i<n;i++)
		{
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		getrt(1,-1);
		int tar=-1;
		for(auto v:G[rt])
		{
			if(maxson[v]==maxson[rt])
				tar=v;
		}
		dbg(rt,tar);
		if(tar==-1)
		{
			int to=G[rt][0];
			cout<<rt<<" "<<to<<'\n';
			cout<<rt<<" "<<to<<'\n';
		}
		else{
			pi edge=dfs(rt,tar);
			cout<<edge.first<<" "<<edge.second<<'\n';
			cout<<edge.second<<" "<<tar<<'\n';
		}
	}
}