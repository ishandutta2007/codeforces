#include<bits/stdc++.h>
#define N 100000
using namespace std;
int n,m;
vector<pair<int,int> > e[N+5];
long long dis[N+5];
vector<pair<long long,long long> > a;
namespace LCT
{
    struct node
    {
        int fa,son[2];
        int tag,time;
    }t[N+5];
    #define get(x) (x==t[t[x].fa].son[1])
    #define is_root(x) (x!=t[t[x].fa].son[0] && x!=t[t[x].fa].son[1])
    inline void push_down(int x)
    {
        if(t[x].tag) t[t[x].son[0]].tag=t[t[x].son[1]].tag=t[x].time=t[x].tag,t[x].tag=0;
    }
    inline void rotate(int x)
    {
        int f=t[x].fa,ff=t[f].fa,k=get(x);
        if(!is_root(f)) t[ff].son[get(f)]=x;
        t[f].son[k]=t[x].son[k^1],t[t[f].son[k]].fa=f;
        t[x].fa=ff,t[x].son[k^1]=f,t[f].fa=x;
    }
    inline void splay(int x)
    {
        static int st[N+5];int p=x,top=1;
        for(st[1]=x;!is_root(p);) st[++top]=p=t[p].fa;
        for(;top;--top) push_down(st[top]);
        for(p=t[x].fa;!is_root(x);rotate(x),p=t[x].fa)
            if(!is_root(p)) rotate(get(p)==get(x)?p:x);
    }
    inline void access(int u,int time)
    {
        for(int x=u,p=0;x;p=x,x=t[x].fa) if(splay(x),p)
            a.push_back({t[x].time+dis[x],time+dis[x]}),t[x].son[1]=p;
        splay(u),t[t[u].son[0]].tag=time;
    }
}
using namespace LCT;
#define y edge.first
#define d edge.second
inline void dfs(int x,int fa)
{
    t[x].fa=fa,t[x].time=-dis[x];
    for(pair<int,int> edge:e[x]) if(y!=fa)
        t[x].son[1]=y,dis[y]=dis[x]+d,dfs(y,x);
}
#undef y
#undef d
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1,u,v,d;i<n;++i)
    {
        scanf("%d %d %d",&u,&v,&d);
        e[u].push_back({v,d});
        e[v].push_back({u,d});
    }
    dfs(1,0);
    for(int i=1,s,t;i<=m;++i)
        scanf("%d %d",&s,&t),access(s,t);
    sort(a.begin(),a.end());
    priority_queue<long long,vector<long long>,greater<long long> > q;
    long long last=0;
    unsigned i=0;
    while(!q.empty() || i!=a.size())
    {
        if(q.empty()) last=a[i].first;
        while(i!=a.size() && a[i].first==last)
            q.push(a[i++].second);
        if(last==q.top())
        {
            int cnt=0;
            for(pair<long long,long long> x:a) if(x.second<last) ++cnt;
            return printf("%lld %d",last,cnt),0;
        }
        q.pop(),++last;
    }
    return printf("-1 %d",(int)a.size()),0;
}