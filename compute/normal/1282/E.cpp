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
bool vis[maxn];
tuple<int,int,int> all[maxn];
int cnt[maxn];
vi per;
vi ans;
map<pi,vi> edge;
bool ok(int x)
{
	if(vis[x]) return false;
	int a,b,c;
	tie(a,b,c)=all[x];
	return cnt[a]==1||cnt[b]==1||cnt[c]==1;
}
void dfs(int u)
{
	vis[u]=1;
	ans.push_back(u);
	dbg(u);
	int a,b,c;
	tie(a,b,c)=all[u];
	cnt[a]--;
	cnt[b]--;
	cnt[c]--;
	for(auto v:edge[make_pair(a,b)])
	{
		if(ok(v))
			dfs(v);
	}
	for(auto v:edge[make_pair(a,c)])
	{
		if(ok(v))
			dfs(v);
	}
	for(auto v:edge[make_pair(b,c)])
	{
		if(ok(v))
			dfs(v);
	}
}
bool avis[maxn];
void getans(int u)
{
	if(avis[u]) return;
	avis[u]=1;
	per.push_back(u);
	for(auto v:G[u])
		getans(v);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		per.clear();
		ans.clear();
		edge.clear();
		for(int i=0;i<=n;i++) cnt[i]=0,G[i].clear(),vis[i]=0,avis[i]=0;
		for(int i=1,a,b,c;i<=n-2;i++)
		{
			cin>>a>>b>>c;
			if(a>b) swap(a,b);
			if(b>c) swap(b,c);
			if(a>b) swap(a,b);
			cnt[a]++;
			cnt[b]++;
			cnt[c]++;
			edge[make_pair(a,b)].push_back(i);
			edge[make_pair(b,c)].push_back(i);
			edge[make_pair(a,c)].push_back(i);
			all[i]={a,b,c};
		}
		for(auto &u:edge)
		{
			if(u.second.size()==1)
			{
				G[u.first.first].push_back(u.first.second);
				G[u.first.second].push_back(u.first.first);
			}
		}
		for(int i=1;i<=n-2;i++)
		{
			if(ok(i))
				dfs(i);
		}
		getans(1);
		print(per);
		print(ans);
	}
}