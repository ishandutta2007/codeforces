#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppp;
#define MAXN 1000005

vector<pii> g[MAXN];
vector<ppp> edges;
int d[MAXN],ttt[MAXN];
int lca[MAXN][18],mlca[MAXN][18],p[MAXN],lg[MAXN],level[MAXN];
int ee[MAXN][2];

int f(int u)
{
    if(d[u]<0)
        return u;
    d[u]=f(d[u]);
    return d[u];
}

bool join(ppp x)
{
    int u=x.second.first;
    int v=x.second.second;
    int uu=u,vv=v;
//    cout << u << ' ' << v << '\n';
    int w=x.first.first;
    u=f(u),v=f(v);
    if(u==v)
        return 0;
    if(d[u]>d[v])
        swap(u,v);
    g[vv].push_back(pii(uu,w));
    g[uu].push_back(pii(vv,w));
    d[u]+=d[v];
    d[v]=u;
    return 1;
}

void build_sparse()
{
    queue<int> q;
    p[0]=-1;
    for(q.push(0);!q.empty();q.pop())
    {
        int u=q.front();
        for(auto y : g[u])
        {
            int v=y.first;
            int w=y.second;
            if(v==p[u])
                continue;

            p[v]=u;
            level[v]=level[u]+1;
            q.push(v);

            lca[v][0]=u;
            mlca[v][0]=w;
            for(int i=1;i<=lg[level[v]];i++)
            {
                lca[v][i]=lca[lca[v][i-1]][i-1];
                mlca[v][i]=max(mlca[v][i-1],mlca[lca[v][i-1]][i-1]);
            }
        }
    }
}

int query(int u,int v)
{
    int res=0;
    if(level[u]<level[v])
        swap(u,v);
    if(level[u]!=level[v])
        for(int i=lg[level[u]];i>=0;i--)
            if(level[u]-(1<<i)>=level[v])
            {
                res=max(res,mlca[u][i]);
                u=lca[u][i];
            }

    if(u==v)
        return res;

    for(int i=lg[level[u]];i>=0;i--)
        if(lca[u][i]!=lca[v][i])
        {
            res=max(res,max(mlca[u][i],mlca[v][i]));
            u=lca[u][i];
            v=lca[v][i];
        }
    return max(res,max(mlca[u][0],mlca[v][0]));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    lg[0]=-1;
    for(int i=1;i<MAXN;i++)
        lg[i]=(lg[i-1]+!(i&(i-1)));

    int n,m,u,v,w;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        d[i]=-1;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v >> w;
        u--,v--;
        ee[i][0]=u;
        ee[i][1]=v;
        edges.push_back(ppp(pii(w,i),pii(u,v)));
    }

    sort(edges.begin(),edges.end());
    for(int i=0;i<m;i++)
    {
        auto y=edges[i];
        if(join(y))
            ttt[y.first.second]=1;
    }

    build_sparse();

    for(int i=0;i<m;i++)
        if(!ttt[i])
            db(query(ee[i][0],ee[i][1]))

    return 0;
}