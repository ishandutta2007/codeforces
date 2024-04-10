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
const int maxn=2e5+7;
vi G[maxn];
pi dp[maxn][2];
bool chd[maxn];
inline bool opt(pi a, pi b)
{
    if(a.first>b.first) return true;
    else if(a.first==b.first&&a.second<b.second) return true;
    return false;
}
pi dfs(int u,int ch=0,int fa=-1)
{
    if(dp[u][ch].first&&dp[u][ch].second) return dp[u][ch];
    pi ret={0,1};
    for(auto v:G[u])if(v!=fa)
    {
        pi cv=dfs(v,0,u);
        ret.first+=cv.first;
        ret.second+=cv.second;
    }
    if(!ch)
    {
    pi cur={1,G[u].size()};
    for(auto v:G[u])if(v!=fa)
    {
        pi cv=dfs(v,1,u);
        cur.first+=cv.first;
        cur.second+=cv.second;
    }
    if(opt(cur,ret)) ret=cur;
    }
    return dp[u][ch]=ret;
}
void getans(int u,int ch,int fa=-1)
{
    if(ch)
    {
        for(auto v:G[u])if(v!=fa)
            getans(v,0,u);
    }
    else{
        pi ret={0,1};
    for(auto v:G[u])if(v!=fa)
    {
        pi cv=dfs(v,0,u);
        ret.first+=cv.first;
        ret.second+=cv.second;
    }
        for(auto v:G[u])if(v!=fa)
        {
            if(ret==dp[u][ch])
                getans(v,0,u);
            else getans(v,1,u);
        }
        if(ret!=dp[u][ch]) chd[u]=1;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(n==2)
    {
        cout<<"2 2\n";
        cout<<"1 1\n";
        return 0;
    }
    pi bst=dfs(1);
    cout<<bst.first<<" "<<bst.second<<'\n';
    getans(1,0);
    for(int i=1;i<=n;i++)
    {
        //dbg(i,chd[i]);
        int ans=chd[i]?G[i].size():1;
        cout<<ans<<" \n"[i==n];
    }

}