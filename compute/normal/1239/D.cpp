#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> PII;
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
const int INF=0x3f3f3f3f;

const int maxn=1e6+7;
vi G[maxn];
int dfn[maxn], low[maxn], bel[maxn];
vvc<int> idx;
int n, m;
int ti, scc; //
stack<int> st;
void dfs(int u)
{
    dfn[u] = low[u] = ++ti;
    st.push(u);
    for (auto v:G[u])
    {
        if (!dfn[v])
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (!bel[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u])
    {
        scc++;
        idx.push_back(vi());
        while (1)
        {
            int t = st.top();
            st.pop();
            bel[t] = scc;
            idx.back().push_back(t);
            if (u == t)
                break;
        }
    }
}
void SCC()
{
    idx.clear();
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            dfs(i);
    }
}
void init(int n)
{
    ti=0,scc=0;
    for(int i=0;i<=n;i++)
    {
        G[i].clear();
        dfn[i]=0,bel[i]=0;
    }
}
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        init(n);
        for(int i=0,u,v;i<m;i++)
        {
            cin>>u>>v;
            if(u==v) continue;
            G[u].push_back(v);
        }
        SCC();
        if(scc==1) cout<<"No\n";
        else{
            vi ans=idx[0];
            vi c(n+1);
            for(auto u:ans) c[u]=1;
            vi ans2;
            for(int i=1;i<=n;i++) if(!c[i]) ans2.push_back(i);
            cout<<"Yes\n";
            print(ans.size(),2);
            print(ans2.size());
            print(ans);
            print(ans2);
        }
    }
}