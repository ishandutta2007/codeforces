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
const int maxn=3e5+7;
int p[maxn];
vi G[maxn];
int fa[maxn];
int deg[maxn];
int Find(int x)
{
	return x==fa[x]?x:fa[x]=Find(fa[x]);
}
void Union(int x,int y)
{
	x=Find(x),y=Find(y);
	fa[x]=y;
}
vi res[maxn];
vi block[maxn];
void add(int u,int v)
{
	u=Find(u);
	v=Find(v);
	if(u==v) return;
	G[u].push_back(v);
	deg[v]++;
}
vi ans;
int dd[maxn];
int nxt[maxn];
void solve(int x)
{
	if(x==0) return;
	for(auto u:block[x])
	{
		int pa=p[u];
		int fp=Find(pa);
		int fu=Find(u);
		if(fp==fu) res[pa].push_back(u),dd[u]++;
	}
	int rt=-1;
	for(auto u:block[x])
	{
		if(!dd[u]) rt=u;
	}
	if(rt==-1) return;
	while(rt!=-1)
	{
		ans.push_back(rt);
		for(auto v:res[rt])
			dd[v]--;
		rt=nxt[rt];
		if(dd[rt]) return;
	}
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	memset(nxt,-1,sizeof(nxt));
	int n,k;
	cin>>n>>k;
	for(int i=0;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=0,u,v;i<k;i++)
	{
		cin>>u>>v;
		Union(u,v);
		res[u].push_back(v);
		nxt[u]=v;
		dd[v]++;
	}
	for(int i=1;i<=n;i++)
	{
		int id=Find(i);
		block[id].push_back(i);
		add(p[i],id);
	}
	queue<int> q;
	for(int i=0;i<=n;i++)
	{
		if(!deg[i]) q.push(i);
	}
	while(!q.empty())
	{
		auto u=q.front();
		q.pop();
		solve(u);
		for(auto v:G[u])
		{
			deg[v]--;
			if(!deg[v]) q.push(v);
		}
	}
	if(ans.size()!=n) print(0);
	else print(ans);
}