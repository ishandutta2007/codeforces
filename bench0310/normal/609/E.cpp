#include <bits/stdc++.h>

using namespace std;

const int N=200005;
vector<pair<int,int>> v[N];
vector<int> depth(N);
vector<vector<int>> p(N,vector<int>(20,0));
vector<vector<int>> lift(N,vector<int>(20,0));

void dfs(int a)
{
    if(p[a][0]) depth[a]=depth[p[a][0]]+1;
    for(int i=1;i<20;i++)
    {
        if(p[a][i-1]==0) break;
        p[a][i]=p[p[a][i-1]][i-1];
        lift[a][i]=max(lift[a][i-1],lift[p[a][i-1]][i-1]);
    }
    for(pair<int,int> t:v[a])
    {
        int to=t.first;
        if(to==p[a][0]) continue;
        p[to][0]=a;
        lift[to][0]=t.second;
        dfs(to);
    }
}

int lca(int a,int b)
{
    if(depth[a]<depth[b]) swap(a,b);
    int res=0;
    for(int i=19;i>=0;i--)
    {
        if(p[a][i]==0||depth[p[a][i]]<depth[b]) continue;
        res=max(res,lift[a][i]);
        a=p[a][i];
    }
    if(a==b) return res;
    for(int i=19;i>=0;i--)
    {
        if(p[a][i]==0||p[b][i]==0||p[a][i]==p[b][i]) continue;
        res=max(res,lift[a][i]);
        res=max(res,lift[b][i]);
        a=p[a][i];
        b=p[b][i];
    }
    res=max(res,lift[a][0]);
    res=max(res,lift[b][0]);
    return res;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<array<int,3>> edges(m);
    vector<array<int,3>> kruskal(m);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        edges[i]={a,b,c};
        kruskal[i]={c,a,b};
    }
    sort(kruskal.begin(),kruskal.end());
    vector<int> par(n+1);
    vector<int> sz(n+1,1);
    for(int i=1;i<=n;i++) par[i]=i;
    long long mst=0;
    function<int(int)> find_parent=[&](int a)->int
    {
        if(par[a]==a) return a;
        else return par[a]=find_parent(par[a]);
    };
    auto merge_sets=[&](int a,int b)->bool
    {
        a=find_parent(a);
        b=find_parent(b);
        if(a==b) return 0;
        if(sz[a]<sz[b]) swap(a,b);
        par[b]=a;
        sz[a]+=sz[b];
        return 1;
    };
    for(array<int,3> e:kruskal)
    {
        int a,b,c;
        tie(a,b,c)=make_tuple(e[1],e[2],e[0]);
        if(merge_sets(a,b))
        {
            mst+=c;
            v[a].push_back({b,c});
            v[b].push_back({a,c});
        }
    }
    dfs(1);
    for(array<int,3> e:edges) printf("%I64d\n",mst+e[2]-lca(e[0],e[1]));
    return 0;
}