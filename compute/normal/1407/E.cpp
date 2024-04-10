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
const int maxn=5e5+7;
vi G[maxn][2];
bool vis[maxn][2];
int dis[maxn];
int col[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	for(int i=0,u,v,t;i<m;i++)
	{
		cin>>u>>v>>t;
		G[v][t].push_back(u);
	}
	memset(dis,-1,sizeof(dis));
	queue<int> q;
	q.push(n);
	dis[n]=0;
	while(!q.empty())
	{
		auto u=q.front();q.pop();
		for(auto v:G[u][0])
		{
			if(!vis[v][0])
			{
				vis[v][0]=1;
				if(vis[v][1])
				{
					col[v]=0;
					dis[v]=dis[u]+1;
					q.push(v);
				}
				else col[v]=1;
			}
		}
		for(auto v:G[u][1])
		{
			if(!vis[v][1])
			{
				vis[v][1]=1;
				if(vis[v][0])
				{
					col[v]=1;
					dis[v]=dis[u]+1;
					q.push(v);
				}
				else col[v]=0;
			}
		}
	}
	print(dis[1]);
	for(int i=1;i<=n;i++) cout<<col[i];
	cout<<'\n';
}