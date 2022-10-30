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
vi G[maxn];
int vis[maxn];
int cnt;
void dfs(int u)
{
    if(vis[u]) return;
    vis[u]=1;
    cnt++;
    for(auto v:G[u]) dfs(v);
}
void solve(int u)
{
    for(auto v:G[u]) vis[v]=1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<=n;i++) G[i].clear(),vis[i]=0;
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        cnt=0;
        dfs(1);
        if(cnt!=n) cout<<"NO\n";
        else{
            cout<<"YES\n";
            for(int i=0;i<=n;i++) vis[i]=0;
            queue<int> q;
            q.push(1);
            vi ans;
            while(!q.empty())
            {
                auto u=q.front();q.pop();
                if(vis[u]) continue;
                ans.push_back(u);
                vis[u]=1;
                for(auto v:G[u])
                {
                    if(!vis[v])
                    {
                        vis[v]=1;
                        for(auto vv:G[v]) q.push(vv);
                    }
                }
            }
            print(ans.size());
            print(ans);
        }
    }
}