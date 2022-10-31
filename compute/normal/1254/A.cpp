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
const int maxn=104;
char maze[maxn][maxn];
vector<char> mp;
bool vis[maxn][maxn];
int avg,cc;
char ans[maxn][maxn];
int r,c,k;
void dfs(int x,int y,int dir,int cnt,int cur)
{
    if(x>=r) return;
    if(y>=c) 
    {
        dfs(x+1,y-1,-1,cnt,cur);
        return;
    }
    if(y<0) 
    {
        dfs(x+1,0,1,cnt,cur);
        return;
    }
    //dbg(x,y);
    ans[x][y]=mp[cur];
    if(maze[x][y]=='R')
    {
        cnt++;
        if(cnt==(avg+(cc!=0)))
        {
            if(cc) cc--;
            cnt=0;
            cur++;
            if(cur==k) cur=k-1;
        }
    }
    dfs(x,y+dir,dir,cnt,cur);
}
void solve()
{
    dfs(0,0,1,0,0);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            printf("%c",ans[i][j]);
        puts("");
    }
}
int main()
{
    int T;
    for(int i=0;i<26;i++) mp.push_back(i+'a');
    for(int i=0;i<26;i++) mp.push_back(i+'A');
    for(int i=0;i<10;i++) mp.push_back(i+'0');
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&r,&c,&k);
        int R=0;
        for(int i=0;i<r;i++)
        {
            scanf("%s",maze[i]);
            for(int j=0;j<c;j++)
                if(maze[i][j]=='R') R++;
        }
        avg=R/k;
        cc=R%k;
        solve();
    }
}