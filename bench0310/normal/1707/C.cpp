#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v[n+1];
    vector<array<int,2>> edges(m+1,{0,0});
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        edges[i]={a,b};
    }
    vector<int> p(n+1,0);
    for(int i=1;i<=n;i++) p[i]=i;
    vector<int> sz(n+1,1);
    function<int(int)> find_set=[&](int a)->int
    {
        if(a==p[a]) return a;
        else return p[a]=find_set(p[a]);
    };
    auto merge_sets=[&](int a,int b)->bool
    {
        a=find_set(a);
        b=find_set(b);
        if(a==b) return 0;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a;
        sz[a]+=sz[b];
        return 1;
    };
    vector<int> g[n+1];
    vector<bool> mst(m+1,0);
    for(int i=1;i<=m;i++)
    {
        auto [a,b]=edges[i];
        if(merge_sets(a,b))
        {
            mst[i]=1;
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }
    vector<int> depth(n+1,0);
    vector<int> tin(n+1,0);
    vector<int> tout(n+1,0);
    int tcnt=0;
    vector<int> h(n+1,0);
    vector<array<int,17>> u(n+1);
    for(int i=0;i<=n;i++) u[i].fill(0);
    int bad=m-(n-1);
    function<void(int)> dfs=[&](int a)
    {
        depth[a]=depth[u[a][0]]+1;
        for(int i=1;i<17;i++) u[a][i]=u[u[a][i-1]][i-1];
        tin[a]=++tcnt;
        h[tcnt]=a;
        for(int to:g[a])
        {
            if(to==u[a][0]) continue;
            u[to][0]=a;
            dfs(to);
        }
        tout[a]=tcnt;
    };
    dfs(1);
    vector<int> d(n+2,0);
    auto add=[&](int l,int r,int x=1)
    {
        d[l]+=x;
        d[r+1]-=x;
    };
    for(int i=1;i<=m;i++)
    {
        auto [a,b]=edges[i];
        if(mst[i]==0)
        {
            if(depth[a]>depth[b]) swap(a,b);
            if(tin[a]<=tin[b]&&tin[b]<=tout[a])
            {
                int x=b;
                for(int j=16;j>=0;j--) if(depth[u[x][j]]>=depth[a]+1) x=u[x][j];
                add(tin[b],tout[b]);
                add(1,n);
                add(tin[x],tout[x],-1);
            }
            else
            {
                add(tin[a],tout[a]);
                add(tin[b],tout[b]);
            }
        }
    }
    int s=0;
    string res(n+1,'0');
    for(int i=1;i<=n;i++)
    {
        s+=d[i];
        res[h[i]]=char('0'+(s==bad));
    }
    cout << res.substr(1,n) << "\n";
    return 0;
}