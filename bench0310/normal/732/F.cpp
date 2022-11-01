#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=400005;
vector<array<int,2>> v[N]; //original graph
vector<int> depth(N,0);
vector<int> low(N,0);
vector<int> up(N,0); //id of edge connecting a vertex with its parent in the DFS tree
vector<array<int,2>> g[N]; //bridge graph
vector<int> idx(N,0); //id of vertex in bridge graph
int bidx=1;
vector<bool> bridge(N,0);
vector<array<int,2>> res(N); //orientation of edges in current version
vector<int> cnt(N,0); //number of vertices in vertex i of bridge graph
vector<int> val(N,0); //current val in DAG, initially set to cnt
vector<int> req(N,0); //current req in DAG
vector<array<int,2>> h(N); //reverse id

void dfs1(int a,int p=0)
{
    depth[a]=depth[p]+1;
    low[a]=depth[a];
    for(auto [to,id]:v[a])
    {
        if(depth[to]!=0)
        {
            if(to!=p) low[a]=min(low[a],depth[to]);
            continue;
        }
        up[to]=id;
        dfs1(to,a);
        low[a]=min(low[a],low[to]);
    }
    if(p!=0&&low[a]==depth[a]) bridge[up[a]]=1;
}

void dfs2(int a,int p=0)
{
    idx[a]=bidx;
    depth[a]=depth[p]+1;
    for(auto [to,id]:v[a])
    {
        if(to==p||bridge[id]==1) continue;
        if(depth[to]!=0)
        {
            if(depth[to]<depth[a]) res[id]={a,to};
            continue;
        }
        res[id]={a,to};
        dfs2(to,a);
    }
}

bool solve(int ini)
{
    int n=bidx-1;
    queue<int> q;
    vector<int> deg(n+1,0);
    for(int i=1;i<=n;i++)
    {
        val[i]=cnt[i];
        req[i]=ini;
        deg[i]=g[i].size();
        if(deg[i]==1) q.push(i);
    }
    while(!q.empty())
    {
        int c=q.front();
        q.pop();
        int a=0;
        int id;
        for(auto[x,y]:g[c]) if(deg[x]!=0) tie(a,id)={x,y};
        if(a==0) return (req[c]<=val[c]);
        deg[a]--;
        if(deg[a]==1) q.push(a);
        if(req[c]<=val[c])
        {
            val[a]+=val[c];
            if(a<c) res[id]={h[id][0],h[id][1]};
            else res[id]={h[id][1],h[id][0]};
        }
        else
        {
            req[a]=max(req[a],req[c]-val[c]);
            if(c<a) res[id]={h[id][0],h[id][1]};
            else res[id]={h[id][1],h[id][0]};
        }
        deg[c]=0;
    }
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<array<int,2>> edges(m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back({b,i});
        v[b].push_back({a,i});
        edges[i]={a,b};
    }
    dfs1(1);
    depth.assign(N,0);
    for(int i=1;i<=n;i++)
    {
        if(idx[i]==0)
        {
            dfs2(i);
            bidx++;
        }
    }
    vector<int> c(n+1,0);
    for(int i=1;i<=n;i++) c[idx[i]]++;
    for(int i=1;i<=n;i++) cnt[idx[i]]=c[idx[i]];
    for(int i=0;i<m;i++)
    {
        if(bridge[i]==1)
        {
            auto [a,b]=edges[i];
            g[idx[a]].push_back({idx[b],i});
            g[idx[b]].push_back({idx[a],i});
            if(idx[a]<idx[b]) h[i]={a,b};
            else h[i]={b,a};
        }
    }
    int l=0,r=n+1;
    while(l<r-1)
    {
        int mid=(l+r)/2;
        if(solve(mid)==1) l=mid;
        else r=mid;
    }
    solve(l);
    printf("%d\n",l);
    for(int i=0;i<m;i++) printf("%d %d\n",res[i][0],res[i][1]);
    return 0;
}