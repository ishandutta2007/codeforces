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
const int maxn=5e3+7;
const int mod=998244353;
vi G[maxn];
vi dp[maxn];
int n,k;

void merge(int u,int v)
{
    vi nxt(max(dp[u].size(),dp[v].size()+1));
    for(int i=0;i<dp[u].size();i++)
    {
        for(int j=0;j<dp[v].size();j++)
        {
            if(i+j+1<=k)
                nxt[max(i,j+1)]=(nxt[max(i,j+1)]+1LL*dp[u][i]*dp[v][j]%mod)%mod;
            if(i<=k&&j<=k)
                nxt[i]=(nxt[i]+1LL*dp[u][i]*dp[v][j])%mod;
        }
    }
    dp[u]=nxt;
}
void dfs(int u,int fa=-1)
{
    dp[u]=vi(1,1);
    for(auto v:G[u])if(v!=fa)
    {
        dfs(v,u);
        merge(u,v);
    dbg(u,dp[u]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1);
    ll ans=0;
    for(auto u:dp[1]) ans=(ans+u)%mod;
    print(ans);
}