#include <bits/stdc++.h>

using namespace std;

const int N=100005;
vector<int> v[N];
vector<vector<int>> p(N,vector<int>(17,0));
vector<int> d(N,0);
vector<int> par(N,0);

int find_set(int a)
{
    if(a==par[a]) return a;
    else return par[a]=find_set(par[a]);
}

void merge_sets(int a,int b)
{
    a=find_set(a);
    b=find_set(b);
    par[a]=b;
}

void dfs(int a)
{
    d[a]=d[p[a][0]]+1;
    for(int i=1;i<17;i++) p[a][i]=p[p[a][i-1]][i-1];
    for(int to:v[a])
    {
        if(to==p[a][0]) continue;
        dfs(to);
    }
}

int lca(int a,int b)
{
    if(d[a]>d[b]) swap(a,b);
    for(int i=16;i>=0;i--) if(d[p[b][i]]>=d[a]) b=p[b][i];
    if(a==b) return a;
    for(int i=16;i>=0;i--)
    {
        if(p[a][i]!=p[b][i])
        {
            a=p[a][i];
            b=p[b][i];
        }
    }
    return p[a][0];
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) par[i]=i;
    vector<array<int,3>> q(m);
    vector<int> up(m+1,0);
    vector<int> down(m+1,0);
    int idx=1;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&q[i][0],&q[i][1]);
        if(q[i][0]!=2) scanf("%d",&q[i][2]);
        auto [t,x,y]=q[i];
        if(t==1)
        {
            merge_sets(x,y);
            v[x].push_back(y);
            v[y].push_back(x);
            p[x][0]=y;
        }
        else if(t==2)
        {
            up[idx]=find_set(x);
            down[idx]=x;
            idx++;
        }
    }
    for(int i=1;i<=n;i++) if(p[i][0]==0) dfs(i);
    for(int i=0;i<m;i++)
    {
        auto [t,x,id]=q[i];
        if(t==3)
        {
            if(find_set(x)==find_set(down[id])&&lca(down[id],x)==x&&lca(x,up[id])==up[id]) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}