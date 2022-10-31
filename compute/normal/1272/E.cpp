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
const int maxn=2e5+7;
int a[maxn];
int n;
vi G[maxn];
int dis[maxn];
struct Node{
	int u,dis;
	bool operator<(const Node&a) const{
		return dis>a.dis;
	}
};
int ans[maxn];
bool vis[maxn];
void dij(int st)
{
	memset(dis,0x3f,sizeof(dis));
	dis[st]=0;
	memset(vis,0,sizeof(vis));
	priority_queue<Node> q;
	q.push({st,0});
	while(!q.empty())
	{
		auto u=q.top();
		q.pop();
		if(vis[u.u]) continue;
		vis[u.u]=1;
		for(auto v:G[u.u]){
			int w=1;
			if(v>n||u.u>n) w=0;
			if(dis[v]>dis[u.u]+w){
				dis[v]=dis[u.u]+w;
				q.push({v,dis[v]});
			}
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(i-a[i]>=1)
			G[i-a[i]].push_back(i);
		if(a[i]+i<=n) G[a[i]+i].push_back(i);
		if(a[i]&1) 
			G[n+1].push_back(i);
	}
	dij(n+1);
	for(int i=1;i<=n;i++)
	{
		if((a[i]&1)==0){
			ans[i]=dis[i];
		}
		G[i].clear();
	}
	for(int i=1;i<=n;i++) 
	{
		if(i-a[i]>=1)
			G[i-a[i]].push_back(i);
		if(a[i]+i<=n) G[a[i]+i].push_back(i);
		if((a[i]&1)==0) {
			G[n+2].push_back(i);
		}
	}
	dij(n+2);
	for(int i=1;i<=n;i++)
	{
		if((a[i]&1)==1){
			ans[i]=dis[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(ans[i]==INF) ans[i]=-1;
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}