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
const int INF=0x3f3f3f3f;
const int maxn=1e5+7;
set<int> G[maxn];
bool vis[maxn];
vector<int> tmp;
set<int> tot;
void solve()
{
    for(auto v:tmp) tot.erase(v);
    tmp.clear();
}
int n,m;
int work()
{
    int ans=-1;
    for(int i=1;i<=n;i++) tot.insert(i);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        queue<int> q;
        q.push(i);
        tot.erase(i);
        while(!q.empty())
        {
            int u=q.front();q.pop();
            vis[u]=1;
            for(auto v:tot)
            {
                if(G[u].find(v)==G[u].end()) 
                {
                    G[u].erase(v);
                    q.push(v);
                    tmp.push_back(v);
                }
            }
            solve();
        }
        ans++;
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0,u,v;i<m;i++)
    {
        scanf("%d%d",&u,&v);
        G[u].insert(v);
        G[v].insert(u);
    }
    printf("%d\n",work());
}