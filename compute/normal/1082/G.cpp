#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+7;
const long long INF=0x3f3f3f3f3f3f3f3f;
struct Edge{
    int from,to;
    long long cap,flow;
};
struct DINIC{
    int n,m,s,t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool vis[maxn];
    long long d[maxn];
    int cur[maxn];

    void AddEdge(int from,int to,long long cap,int c=0)//c0
    {
        edges.push_back(Edge {from,to,cap,0});
        edges.push_back(Edge {to,from,c,0});
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool BFS()
    {
        memset(vis,0,sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s]=0;
        vis[s]=1;
        while(!Q.empty())
        {
            int x=Q.front();Q.pop();
            for(int i=0;i<G[x].size();i++)
            {
                Edge& e=edges[G[x][i]];
                if(!vis[e.to]&&e.cap>e.flow)
                {
                    vis[e.to]=1;
                    d[e.to]=d[x]+1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    long long DFS(int x,long long a)
    {
        if(x==t||a==0) return a;
        long long flow=0,f;
        for(int& i=cur[x];i<G[x].size();i++)
        {
            Edge& e=edges[G[x][i]];
            if(d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0)
            {
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0) break;
            }
        }
        return flow;
    }
    long long Maxflow(int s,int t)
    {
        this->s=s;this->t=t;
        long long flow=0;
        while(BFS())
        {
            memset(cur,0,sizeof(cur));
            flow+=DFS(s,INF);
        }
        return flow;
    }
}F;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int s=0,t=n+m+1;
    long long tot=0;
    long long pt;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&pt);
        F.AddEdge(i,t,pt);
    }
    long long u,v,cost;
    for(int i=1;i<=m;i++)
    {
        scanf("%lld%lld%lld",&u,&v,&cost);
        F.AddEdge(n+i,u,INF);
        F.AddEdge(n+i,v,INF);
        F.AddEdge(s,n+i,cost);
        tot+=cost;
    }
    long long ans=tot-F.Maxflow(s,t);
    printf("%lld\n",ans);
}