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
const int maxn=1e3+7;
vi G[maxn];
inline int ask(int u,int v)
{
    cout<<"? "<<u<<" "<<v<<endl;
    int w;
    cin>>w;
    return w;
}
int ans=-1;
void dfs(int u,int top,int fa=-1)
{
    vi son;
    for(auto v:G[u])
        if(v!=fa) son.push_back(v);
    for(int i=1;i<son.size();i+=2)
    {
        int lca=ask(son[i],son[i-1]);
        if(lca!=u)
        {
            assert(lca==son[i]||lca==son[i-1]);
            dfs(lca,lca,u);
            return;
        }
    }
    if(son.size()&1)
        dfs(son.back(),top,u);
    else{
        if(u==top) ans=u;
        else ans=ask(u,top);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,1);
    assert(ans!=-1);
    cout<<"! "<<ans<<endl;
}