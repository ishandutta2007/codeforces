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
const int maxn=4e5+7;
int dfn[maxn], low[maxn], bel[maxn];
ll dep[maxn];
ll g[maxn];
ll gv[maxn];
struct Edge{
	int to,w;
};
vc<Edge> G[maxn];
ll pl[maxn];
int n, m;
int ti, scc; //
stack<int> st;
void dfs(int u, int fa)
{
    dfn[u] = low[u] = ++ti;
    st.push(u);
	for(auto &e:G[u])
    {
		int v=e.to;
        if (!dfn[v])
        {
			dep[v]=dep[u]+e.w;
            dfs(v, u);
			if(low[v]<low[u]) pl[u]=pl[v]+e.w;
            low[u] = min(low[u], low[v]);
        }
        else if (!bel[v])
        {
            low[u] = min(low[u], dfn[v]);
			gv[u]=__gcd(gv[u],dep[u]-dep[v]+e.w);
		}
    }
    if (dfn[u] == low[u])
    {
        scc++;
		vi cur;
        while (1)
        {
            int t = st.top();
			cur.push_back(t);
            st.pop();
            bel[t] = scc;
            if (u == t)
                break;
        }
    }
}
void DCC()
{
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            dfs(i, -1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0,u,v,w;i<m;i++)
	{
		cin>>u>>v>>w;
		G[u].push_back(Edge{v,w});
	}
	DCC();
	for(int i=1;i<=n;i++) g[bel[i]]=__gcd(g[bel[i]],gv[i]);
	int q;
	cin>>q;
	while(q--)
	{
		ll v,s,t;
		cin>>v>>s>>t;
		dbg(bel[v],g[bel[v]]);
		ll cg=__gcd(t,g[bel[v]])%t;
		if(!cg)
		{
			if(!s) cout<<"YES\n";
			else cout<<"NO\n";
		}
		else if(s%cg) cout<<"NO\n";
		else cout<<"YES\n";
	}
}