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
struct Edge{
	int to,w;
};
const int maxn=205;
vc<Edge> G[maxn];
int col[maxn];
bool suc=1;
void dfs(int u,int c)
{
	col[u]=c;
	for(auto &e:G[u])
	{
		int v=e.to;
		if(col[v]!=-1)
		{
			if(col[v]==col[u]) 
			{
				suc=0;
				return;
			}
		}
		else dfs(v,c^1);
	}
}
int d[maxn],inq[maxn],cnt[maxn];
int op[maxn];
int n,m;
int mxans=-1;
void spfa(int st)
{
	memset(d,0x3f,sizeof(d));
	memset(inq,0,sizeof(inq));
	queue<int> q;
	q.push(st);
	d[st]=0;
	cnt[st]=0;
	while(!q.empty())
	{
		auto u=q.front();q.pop();
		inq[u]=0;
		for(auto &e:G[u])
		{
			int v=e.to;
			int w=e.w;
			if(!w) w=1;
			if(d[v]>d[u]+w)
			{
				d[v]=d[u]+w;
				if(!inq[v])
				{
					q.push(v);
					cnt[v]=cnt[u]+1;
					if(cnt[v]>n+1)
					{
						suc=0;
						return;
					}
					inq[v]=1;
				}
			}	
		}
	}
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		if(d[i]<0) return;
		mx=max(mx,d[i]);
	}
	if(mx>mxans)
	{
		mxans=mx;
		for(int i=1;i<=n;i++) op[i]=d[i];
	}
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	memset(col,-1,sizeof(col));
	cin>>n>>m;
	for(int i=0,u,v,w;i<m;i++)
	{
		cin>>u>>v>>w;
		G[u].push_back(Edge{v,w});
		G[v].push_back(Edge{u,-w});
	}
	dfs(1,0);
	if(!suc)
	{
		cout<<"NO\n";
		return 0;
	}
	for(int i=1;i<=n;i++)
		spfa(i);
	if(mxans==-1)
	{
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	cout<<mxans<<'\n';
	vi ans(n);
	for(int i=1;i<=n;i++) ans[i-1]=op[i];
	print(ans);
}