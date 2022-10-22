#include<bits/stdc++.h>
#define N 400000
#define M 600000
using namespace std;
int n1,n2,m,q,head[N+5],cnt=1,S,T,deep[N+5],cur[N+5],match[N+5],id[N+5];
long long sum;
bool vis[N+5];
vector<int> ans;
struct edge
{
    int to,nxt,w;
}e[M*2+5];
#define y e[i].to
inline void add(int u,int v,int w)
{
    e[++cnt]=(edge){v,head[u],w},head[u]=cnt;
    e[++cnt]=(edge){u,head[v],0},head[v]=cnt;
}
inline bool bfs()
{
    queue<int> q;
    memset(deep,-1,sizeof deep);
    deep[S]=0,q.push(S);
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int i=head[x];i;i=e[i].nxt)
            if(e[i].w && deep[y]==-1)
                deep[y]=deep[x]+1,q.push(y);
    }
    return deep[T]!=-1;
}
int dfs(int x,int flow)
{
    if(x==T) return flow;
    int each,out=0;
    for(int &i=cur[x];i;i=e[i].nxt)
        if(e[i].w && deep[y]==deep[x]+1)
        {
            each=dfs(y,min(flow,e[i].w));
            flow-=each,out+=each;
            e[i].w-=each,e[i^1].w+=each;
            if(!flow) return out;
        }
    return out;
}
inline int Dinic()
{
    int ret=0;
    while(bfs()) memcpy(cur,head,sizeof head),ret+=dfs(S,1e9);
    return ret;
}
inline void work()
{
    for(int x=1;x<=n1;++x) for(int i=head[x];i;i=e[i].nxt)
        if(y!=S && !e[i].w) match[match[x]=y]=x,sum+=(id[x]=id[y]=i>>1);
    queue<int> q;
    for(int x=1;x<=n1+n2;++x) if(!id[x]) vis[x]=1,q.push(x);
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(int i=head[x];i;i=e[i].nxt)
            if(y!=S && y!=T && id[y]) 
                if(!vis[match[y]]) vis[match[y]]=1,q.push(match[y]);
    }
    for(int i=1;i<=n1+n2;++i)
        if(!vis[i]) ans.push_back(i),vis[match[i]]=1;
}
inline int get(int x) {return x<=n1?x:n1-x;}
int main()
{
    scanf("%d %d %d %d",&n1,&n2,&m,&q),S=0,T=n1+n2+1;
    for(int i=1,u,v;i<=m;++i)
        scanf("%d %d",&u,&v),add(u,n1+v,1);
    for(int i=1;i<=n1;++i) add(S,i,1);
    for(int i=1;i<=n2;++i) add(n1+i,T,1);
    Dinic(),work();
    for(int opt;q--;)
    {
        scanf("%d",&opt);
        if(opt==1) printf("1\n%d\n%lld\n",get(ans.back()),sum-=id[ans.back()]),ans.pop_back();
        else
        {
            printf("%d\n",(int)ans.size());
            for(int x:ans) printf("%d ",id[x]);
            putchar('\n');
        }
        fflush(stdout);
    }
    return 0;
}