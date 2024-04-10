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
const int maxn=405;
const int mod=998244353;
int g[maxn][maxn];
vi G[maxn];
int f[maxn][maxn];
int d[maxn][maxn];
int n,m;
void work(int x)
{
    queue<int> q;
    q.push(x);
    memset(d[x],0x3f,sizeof(d[x]));
    d[x][x]=0;
    while(!q.empty())
    {
        auto u=q.front();q.pop();
        for(auto v:G[u])
        {
            if(d[x][v]>d[x][u]+1)
            {
                d[x][v]=d[x][u]+1;
                q.push(v);
            }
        }
    }
}
int curfa[maxn];
ll count(vc<pi>& pt,int rt)
{
    sort(pt.begin(),pt.end());
    vi cur;
    cur.push_back(rt);
    curfa[rt]=1;
    int cd=1;
    vi nxt;
    ll ret=1;
    for(auto p:pt)
    {
        if(p.first!=cd)
        {
            cd++;
            for(auto u:cur) curfa[u]=0;
            cur=nxt;
            for(auto u:cur) curfa[u]=1;
            nxt.clear();
        }
        nxt.push_back(p.second);
        int cc=0;
        for(auto v:G[p.second])
        {
            if(curfa[v]) cc++;
        }
        ret=ret*cc%mod;
    }
    for(auto u:cur) curfa[u]=0;
    return ret;
}
void solve(int s,int t)
{
    ll ret=0;
    int dis=d[s][t];
    vi chain(dis+1,-1);
    for(int i=1;i<=n;i++)
    {
        if(d[s][i]+d[t][i]==dis)
        {
            if(chain[d[s][i]]!=-1) return;
            chain[d[s][i]]=i;
        }
    }
    dbg(s,t);
    dbg(chain);
    vvc<pi> elem(dis+1); 
    for(int i=1;i<=n;i++)
    {
        if(d[s][i]+d[t][i]!=dis)
        {
            if((d[s][i]+d[t][i]-dis)%2!=0) return;
            int cad=(d[s][i]+d[t][i]-dis)/2;
            int fad=d[s][i]-cad;
            elem[fad].emplace_back(cad,i);
        }
    }
    ret=1;
    for(int i=0;i<=dis;i++)
    {
        if(chain[i]==-1) return;
        ret=(ret*count(elem[i],chain[i]))%mod;
    }
    f[s][t]=f[t][s]=ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0,u,v;i<m;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
        g[u][v]=g[v][u]=1;
    }
    for(int i=1;i<=n;i++)
        work(i);
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
            solve(i,j);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cout<<f[i][j]<<" \n"[j==n];
    }
}