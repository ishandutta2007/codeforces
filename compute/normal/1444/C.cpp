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
const int maxn=5e5+7;
int fa[maxn],col[maxn],sz[maxn];
void init()
{
	for(int i=0;i<maxn;i++) fa[i]=i,sz[i]=1,col[i]=0;
}
int Find(int x)
{
	return fa[x]==x?x:Find(fa[x]);
}
int getval(int x)
{
	int ret=0;
	while(fa[x]!=x) ret^=col[x],x=fa[x];
	return ret;
}
int c[maxn];
vc<pi> all[maxn];
int ok[maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	init();
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>c[i];
	vc<pi> edge;
	for(int i=1;i<=k;i++) ok[i]=1;
	for(int i=0,u,v;i<m;i++)
	{
		cin>>u>>v;
		if(c[u]>c[v]) swap(u,v);
		if(c[u]!=c[v])
			edge.emplace_back(u,v);
		else if(ok[c[u]]){
			int cc=c[u];
			int colu=getval(u),colv=getval(v);
			u=Find(u),v=Find(v);
			if(u==v&&colu==colv)
				ok[cc]=0;
			else{
				if(sz[u]>sz[v]) swap(u,v);
				sz[v]+=sz[u];
				fa[u]=v;
				col[u]=colu^colv^1;
			}
		}
	}
	auto rollback=[&](vi &cur){
		while(!cur.empty())
		{
			auto u=cur.back();
			sz[fa[u]]-=sz[u],fa[u]=u,col[u]=0;
			cur.pop_back();
		}
	};
	for(auto &e:edge)
	{
		int u=e.first,v=e.second;
		if(!ok[c[v]]) continue;
		all[c[u]].emplace_back(u,v);
	}
	ll ans=0;
	vi suf(k+1);
	suf[k]=ok[k];
	for(int i=k-1;i>=1;i--) suf[i]=suf[i+1]+ok[i];
	for(int i=1;i<k;i++)
	{
		if(ok[i])
			ans+=suf[i+1];
	}
	auto solve=[&](vc<pi> &ae)
	{
		vi opt;
		for(auto &e:ae)
		{
			int u=e.first,v=e.second;
			int colu=getval(u),colv=getval(v);
			u=Find(u),v=Find(v);
			if(u==v&&colu==colv)
			{
				rollback(opt);
				ans--;
				return;
			}
			else{
				if(sz[u]>sz[v]) swap(u,v);
				sz[v]+=sz[u];
				fa[u]=v;
				col[u]=colu^colv^1;
				opt.push_back(u);
			}
		}
		rollback(opt);
	};
	for(int i=1;i<=k;i++)
	{
		if(!ok[i])
			continue;
		sort(all[i].begin(),all[i].end(),[&](pi a,pi b){
			return c[a.second]<c[b.second];
		});
		int cc=i;
		vc<pi> ae;
		for(auto &e:all[i])
		{
			int u=e.first,v=e.second;
			//dbg(u,v,c[u],c[v]);
			if(c[v]!=cc)
			{
				solve(ae);
				ae.clear();
				cc=c[v];
			}
			ae.push_back(e);
		}
		solve(ae);
	}
	print(ans);
}