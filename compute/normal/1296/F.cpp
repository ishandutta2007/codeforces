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
    int to,id;
};
const int maxn=5005;
struct Query{
    int u,v,w;
}q[maxn];
vc<Edge> G[maxn];
int w[maxn];
int tar;
vi edge;
bool dfs(int u,int fa=-1)
{
    if(u==tar) return true;
    for(auto e:G[u])if(e.to!=fa)
    {
        int v=e.to;
        if(dfs(v,u)){
            edge.push_back(e.id);
            return true;
        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].push_back(Edge{v,i});
        G[v].push_back(Edge{u,i});
        w[i]=1;
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        edge.clear();
        cin>>q[i].u>>q[i].v>>q[i].w;
        tar=q[i].v;
        dfs(q[i].u);
        for(auto u:edge) w[u]=max(w[u],q[i].w);
    }
    bool ok=1;
    for(int i=0;i<m;i++)
    {
        edge.clear();
        tar=q[i].v;
        dfs(q[i].u);
        int val=1e6+7;
        for(auto u:edge) val=min(val,w[u]);
        if(val!=q[i].w) ok=0;
    }
    if(!ok) cout<<"-1\n";
    else{
        for(int i=1;i<n;i++) cout<<w[i]<<(i==n-1?'\n':' ');
    }


}