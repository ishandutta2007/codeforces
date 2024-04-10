#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<array<int,2>> v[N];
vector<int> comp(N,0);
vector<int> depth(N,0);
vector<int> low(N,0);
vector<bool> bridge(N,0);
vector<array<int,2>> bridges;
vector<int> id(N,0);
vector<int> g[N];
vector<array<int,2>> val(N,{0,0});
vector<vector<int>> p(N,vector<int>(18,0));
bool ok=1;

void dfs1(int a,int par,int up,int c)
{
    depth[a]=depth[par]+1;
    low[a]=depth[a];
    comp[a]=c;
    for(auto [to,e]:v[a])
    {
        if(e==up) continue;
        if(comp[to]==0) dfs1(to,a,e,c);
        low[a]=min(low[a],low[to]);
    }
    if(par!=0&&low[a]>=depth[a])
    {
        bridge[up]=1;
        bridges.push_back({a,par});
    }
}

void dfs2(int a,int c)
{
    id[a]=c;
    for(auto [to,e]:v[a]) if(bridge[e]==0&&id[to]==0) dfs2(to,c);
}

void dfs3(int a)
{
    depth[a]=depth[p[a][0]]+1;
    for(int i=1;i<18;i++) p[a][i]=p[p[a][i-1]][i-1];
    for(int to:g[a])
    {
        if(to==p[a][0]) continue;
        p[to][0]=a;
        dfs3(to);
    }
}

int lca(int a,int b)
{
    if(depth[a]>depth[b]) swap(a,b);
    for(int i=17;i>=0;i--) if(depth[p[b][i]]>=depth[a]) b=p[b][i];
    if(a==b) return a;
    for(int i=17;i>=0;i--) if(p[a][i]!=p[b][i]) tie(a,b)={p[a][i],p[b][i]};
    return p[a][0];
}

void add(int a,int b)
{
    int l=lca(a,b);
    val[a][0]++;
    val[l][0]--;
    val[b][1]++;
    val[l][1]--;
}

array<int,2> dfs4(int a)
{
    array<int,2> now=val[a];
    for(int to:g[a])
    {
        if(to==p[a][0]) continue;
        array<int,2> tmp=dfs4(to);
        now[0]+=tmp[0];
        now[1]+=tmp[1];
    }
    if(now[0]>0&&now[1]>0) ok=0;
    return now;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
    }
    int idx=1;
    for(int i=1;i<=n;i++) if(comp[i]==0) dfs1(i,0,0,idx++);
    idx=1;
    for(int i=1;i<=n;i++) if(id[i]==0) dfs2(i,idx++);
    for(auto [a,b]:bridges)
    {
        g[id[a]].push_back(id[b]);
        g[id[b]].push_back(id[a]);
    }
    for(int i=1;i<=n;i++) depth[i]=0;
    vector<int> roots;
    for(int i=1;i<idx;i++)
    {
        if(depth[i]==0)
        {
            dfs3(i);
            roots.push_back(i);
        }
    }
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        if(comp[a]!=comp[b]) ok=0;
        else add(id[a],id[b]);
    }
    for(int r:roots) dfs4(r);
    if(ok) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}