#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<set<int>> v(N);
vector<int> sz(N,0);
vector<vector<int>> p(N,vector<int>(17,0));
vector<int> depth(N,0);
vector<int> dad(N,0);
vector<int> val(N,N);

void dfs0(int a)
{
    depth[a]=depth[p[a][0]]+1;
    for(int i=1;i<17;i++) p[a][i]=p[p[a][i-1]][i-1];
    for(int to:v[a])
    {
        if(to==p[a][0]) continue;
        p[to][0]=a;
        dfs0(to);
    }
}

int lca(int a,int b)
{
    if(depth[a]>depth[b]) swap(a,b);
    for(int i=16;i>=0;i--) if(depth[p[b][i]]>=depth[a]) b=p[b][i];
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

int dist(int a,int b)
{
    return depth[a]+depth[b]-2*depth[lca(a,b)];
}

void dfs(int a,int par=0)
{
    sz[a]=1;
    for(int to:v[a])
    {
        if(to==par) continue;
        dfs(to,a);
        sz[a]+=sz[to];
    }
}

int find_centroid(int a,int par,int n)
{
    for(int to:v[a])
    {
        if(to==par) continue;
        if(sz[to]>n/2) return find_centroid(to,a,n);
    }
    return a;
}

void build_centroid(int a,int par=0)
{
    dfs(a);
    int n=sz[a];
    int centroid=find_centroid(a,0,n);
    dad[centroid]=par;
    for(int to:v[centroid])
    {
        v[to].erase(centroid);
        build_centroid(to,centroid);
    }
}

void update(int a)
{
    for(int i=a;i!=0;i=dad[i]) val[i]=min(val[i],dist(a,i));
}

int solve(int a)
{
    int res=N;
    for(int i=a;i!=0;i=dad[i]) res=min(res,val[i]+dist(a,i));
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].insert(b);
        v[b].insert(a);
    }
    dfs0(1);
    build_centroid(1);
    update(1);
    while(m--)
    {
        int t,a;
        cin >> t >> a;
        if(t==1) update(a);
        else cout << solve(a) << "\n";
    }
    return 0;
}