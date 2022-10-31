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
const int maxn=2e5+7;
vi G[maxn];
int dep[maxn];
int d1[maxn],d2[maxn];
int dfs(int u,int d,int fa=-1)
{
    dep[u]=d+1;
    int ret=u;
    for(auto v:G[u])if(v!=fa)
    {
        int t=dfs(v,d+1,u);
        if(dep[t]>dep[ret]) ret=t;
    }
    return ret;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int a=dfs(1,-1);
    int b=dfs(a,-1);
    int ans=dep[b];
    queue<int> q;
    memset(d1,-1,sizeof(d1));
    q.push(a);
    d1[a]=0;
    while(!q.empty())
    {
        auto u=q.front();q.pop();
        for(auto v:G[u])
        {
            if(d1[v]==-1)
            {
                d1[v]=d1[u]+1;
                q.push(v);
            }
        }
    }
    memset(d2,-1,sizeof(d2));
    q.push(b);
    d2[b]=0;
    while(!q.empty())
    {
        auto u=q.front();q.pop();
        for(auto v:G[u])
        {
            if(d2[v]==-1)
            {
                d2[v]=d2[u]+1;
                q.push(v);
            }
        }
    }
    int c=-1;
    int ans2=0;
    for(int i=1;i<=n;i++)
    {
        if(i==a||i==b) continue;
        int dd=d1[i]+d2[i];
        //dbg(i,dd,(dd-ans)/2+ans,ans);
        if((dd-ans)/2+ans>ans2)
        {
            ans2=(dd-ans)/2+ans;
            c=i;
        }
    }
    cout<<ans2<<'\n';
    cout<<a<<" "<<b<<" "<<c<<'\n';
}