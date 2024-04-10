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
const int maxn=1e5+7;
vi G[maxn];
bool vis[maxn];
bool ins[maxn];
int dep[maxn];
int fa[maxn];
int tar;
vi ans;
int rt=-1,rt2=-1;
void dfs(int u,int far=-1,int d=0)
{
    dep[u]=d;
    fa[u]=far;
    ins[u]=1;
    int cc=0;
    //dbg(u,dep[u]);
    for(auto v:G[u])
    {
        if(!ins[v])
            dfs(v,u,d+1);
        else if(dep[v]<dep[u]) cc++;
    }
    //dbg(u,cc);
    if(cc<tar-1)
    {
        bool ok=1;
        for(auto v:G[u])
            if(vis[v]) ok=0;
        if(ok)
        {
            if(ans.size()<tar) ans.push_back(u);
            vis[u]=1;
        }
    }
    else{
        rt=u,rt2=u;
        for(auto v:G[u])
        {
            if(dep[v]<dep[rt2]) rt2=v;
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0,u,v;i<m;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    tar=1;
    while(tar*tar<n) tar++;
    dfs(1);
    if(ans.size()==tar)
    {
        print(1);
        print(ans);
    }
    else{
        assert(rt!=-1);
        print(2);
        ans.clear();
        while(rt!=rt2)
        {
            ans.push_back(rt);
            rt=fa[rt];
        }
        ans.push_back(rt);
        print(ans.size());
        print(ans);
    }
}