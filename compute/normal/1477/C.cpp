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
mt19937 rnd(time(0));
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
inline bool check(pi a,pi b,pi c)
{
    pi d={b.first-a.first,b.second-a.second},e={c.first-b.first,c.second-b.second};
    //dbg(1LL*d.first*e.first+1LL*d.second*e.second);
    return 1LL*d.first*e.first+1LL*d.second*e.second<0;
}
vi ans;
//set<int> rem;
int vis[5005];
int n;
bool suc=0;
vc<pi> pt;
void dfs(int u,int pre)
{
    if(suc) return;
    if(ans.size()==n)
    {
        suc=1;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(vis[i]) continue;
        if(check(pt[pre],pt[u],pt[i]))
        {
            //dbg(pre,u,v);
            ans.push_back(i);
            vis[i]=1;
            dfs(i,u);
            if(suc) return;
            vis[i]=0;
            ans.pop_back();
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    pt=vc<pi>(n);
    for(int i=0;i<n;i++) cin>>pt[i].first>>pt[i].second;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            ans.push_back(i);
            ans.push_back(j);
            vis[i]=vis[j]=1;
            dfs(j,i);
            if(suc) break;
            vis[i]=vis[j]=0;
            ans.clear();
        }
        if(suc) break;
    }
    if(!suc)
    {
        print(-1);
        return 0;
    }
    for(auto &u:ans) u++;
    print(ans);
}