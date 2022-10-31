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
    int to,id;
};
const int maxn=1e5+7;
vc<Edge> G[maxn];
int ans[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].push_back(Edge{v,i});
        G[v].push_back(Edge{u,i});
    }
    if(n==2)
    {
        cout<<0<<'\n';
        return 0;
    }
    int cur=0;
    vi vis(n+1);
    for(int i=1;i<=n;i++)
    {
        if(G[i].size()==1)
        {
            int id=G[i][0].id;
            vis[id]=1;
            ans[id]=cur++;
        }
    }
    for(int i=1;i<n;i++)
    {
        if(!vis[i]) ans[i]=cur++;
    }
    for(int i=1;i<n;i++) print(ans[i]);
}