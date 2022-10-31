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
const int INF=0x3f3f3f3f;
const int maxn=5005;
int org[1<<15];
int dp[1<<15];
int pre[1<<15];
int cnt[15];
ll sum[15];
ll a[15][maxn];
map<ll,PII> pos;
bool vis[15];
PII G[15][maxn];
vector<PII> path[1<<15];
PII ans[15];
void getpath(int st,int ed,int i,int j,int state,vector<PII> pa)
{
    if(i==-1||j==-1) return;
    if(vis[i])
    {
        if(st==i&&ed==j) 
        {
            org[state]=dp[state]=1;
            path[state]=pa;
        }
        return;
    }
    vis[i]=1;
    pa.push_back(make_pair(i,j));
    getpath(st,ed,G[i][j].first,G[i][j].second,state|(1<<i),pa);
}
void getans(int state)
{
    if(org[state])
    {
        int sz=path[state].size();
        for(int i=0;i<sz;i++)
        {
            //cout<<i<<":"<<path[state][i].first<<" "<<path[state][i].second<<endl;
            int pre=(i-1+sz)%sz;
            ans[path[state][i].first]=make_pair(path[state][i].second,path[state][pre].first);
        }
        return;
    }
    getans(pre[state]);
    getans(state^pre[state]);
}
int main()
{
    memset(G,-1,sizeof(G));
    int k;
    scanf("%d",&k);
    ll tot=0;
    for(int i=0;i<k;i++)
    {
        scanf("%d",&cnt[i]);
        for(int j=0;j<cnt[i];j++) 
        {
            scanf("%lld",&a[i][j]);
            tot+=a[i][j];
            pos[a[i][j]]=make_pair(i,j);
            sum[i]+=a[i][j];
        }
    }
    if(tot%k!=0) puts("No");
    else{
        ll tar=tot/k;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<cnt[i];j++)
            {
                ll delta=tar-(sum[i]-a[i][j]);
                if(pos.count(delta))
                {
                    if(pos[delta].first==i)
                        continue;
                    G[i][j]=pos[delta];
                }
            }
        }
        for(int i=0;i<k;i++)
        {
            if(sum[i]==tar)
            {
                org[1<<i]=dp[1<<i]=1;
                path[1<<i]={make_pair(i,0)};
            }
            for(int j=0;j<cnt[i];j++)
            {
                if(G[i][j].first!=-1)
                {
                    memset(vis,0,sizeof(vis));
                    vis[i]=1;
                    vector<PII> tmp={make_pair(i,j)};
                    getpath(i,j,G[i][j].first,G[i][j].second,1<<i,tmp);
                }
            }
        }
        for(int S=1;S<(1<<k);S++)
        {
            for(int T = S; T; T = (T - 1) & S)
            {
                if(dp[T]&&org[S-T])
                {
                    pre[S]=T;
                    dp[S]=1;
                }
            }
        }
        if(!dp[(1<<k)-1]) puts("No");
        else 
        {
            puts("Yes");
            getans((1<<k)-1);
            for(int i=0;i<k;i++)
                printf("%lld %d\n",a[i][ans[i].first],ans[i].second+1);
        }
    }
}