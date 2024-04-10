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
const int mod=1e9+7;
const int maxn=2e5+7;
int d[maxn];
vi G[maxn];
int vis[maxn];
void bfs(int st)
{
    queue<int> q;
    q.push(st);
    vis[st]=1;
    d[st]=0;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(auto v:G[u])
        {
            if(!vis[v])
            {
                d[v]=d[u]+1;
                q.push(v);
                vis[v]=1;
            }
        }
    }
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<=n;i++) G[i].clear(),vis[i]=0;
        int s,t;
        cin>>s>>t;
        for(int i=0,u,v;i<m;i++)
        {
            cin>>u>>v;
            u--,v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        s--,t--;
        vc<vi> dp(n,vi(2));
        bfs(s);
        vc<vi> df(n);
        for(int i=0;i<n;i++)
            df[d[i]].push_back(i);
        dp[s][0]=1;
        for(int i=0;i<n;i++)
        {
            for(auto u:df[i])
            {
                for(auto v:G[u])
                {
                    if(d[v]==d[u])
                        dp[v][1]=(dp[v][1]+dp[u][0])%mod;
                }
            }
            for(auto u:df[i])
            {
                for(auto v:G[u])
                {
                    if(d[v]>d[u])
                    {
                        dp[v][1]=(dp[v][1]+dp[u][1])%mod;
                        dp[v][0]=(dp[v][0]+dp[u][0])%mod;
                    }
                }
            }
        }
        print((dp[t][0]+dp[t][1])%mod);
    }
}