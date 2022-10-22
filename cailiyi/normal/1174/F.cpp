#include<bits/stdc++.h>
#define N 200000
using namespace std;
int n,deep[N+5],siz[N+5],son[N+5],down[N+5],dis1;
vector<int> e[N+5];
inline void dfs(int x,int fa)
{
    deep[x]=fa?deep[fa]+1:0,siz[x]=1;
    for(int y:e[x]) if(y!=fa)
    {
        dfs(y,x),siz[x]+=siz[y];
        if(siz[y]>siz[son[x]]) son[x]=y;
    }
    down[x]=son[x]?down[son[x]]:x;
}
inline int query(bool type,int x)
{
    printf("%c %d\n","ds"[type],x);
    fflush(stdout);
    int ret;
    scanf("%d",&ret);
    return ret;
}
inline void answer(int x)
{
    printf("! %d\n",x);
    fflush(stdout);
    exit(0);
}
int main()
{
    scanf("%d",&n);
    for(int i=1,u,v;i<n;++i)
    {
        scanf("%d %d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    int x=1,dis1=query(0,1);
    if(!dis1) answer(1);
    while(1)
    {
        int dis=query(0,down[x]);
        int len=(dis1+deep[down[x]]-dis)>>1;
        while(deep[x]<len) x=son[x];
        if(deep[x]==dis1) answer(x);
        x=query(1,x);
    }
}