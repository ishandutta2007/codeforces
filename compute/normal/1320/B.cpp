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
vi rG[maxn];
struct D{
    int id,dis;
    bool operator<(const D& a)const{
        return dis>a.dis;
    }
};
bool vis[maxn];
int d[maxn];
vi path;
void dij()
{
    memset(d,0x3f,sizeof(d));
    d[path.back()]=0;
    priority_queue<D> q;
    q.push(D{path.back(),0});
    while(!q.empty())
    {
        auto u=q.top();
        q.pop();
        if(vis[u.id]) continue;
        vis[u.id]=1;
        for(auto v:G[u.id])
        {
            if(d[v]>d[u.id]+1)
            {
                d[v]=d[u.id]+1;
                q.push(D{v,d[v]});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0,u,v;i<m;i++)
    {
        cin>>u>>v;
        G[v].push_back(u);
        rG[u].push_back(v);
    }
    int k;
    cin>>k;
    path=vi(k);
    for(int i=0;i<k;i++) cin>>path[i];
    dij();
    int ans1=0,ans2=0;
    for(int i=1;i<k;i++)
    {
        int u=path[i-1],v=path[i];
        if(d[u]!=d[v]+1) 
        {
            ans1++;
            ans2++;
        }
        else{
            int cnt=0;
            for(auto p:rG[u])
                if(d[u]==d[p]+1) cnt++;
            cnt--;
            if(cnt) ans2++;
        }

    }
    cout<<ans1<<" "<<ans2<<'\n';

}