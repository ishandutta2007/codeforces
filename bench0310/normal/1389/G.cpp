#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<bool> special(n+1,0);
    for(int i=1;i<=k;i++)
    {
        int a;
        cin >> a;
        special[a]=1;
    }
    vector<int> c(n+1,0);
    for(int i=1;i<=n;i++) cin >> c[i];
    vector<int> wtmp(m+1,0);
    for(int i=1;i<=m;i++) cin >> wtmp[i];
    vector<array<int,2>> v[n+1];
    vector<array<int,3>> edges;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
        edges.push_back({a,b,wtmp[i]});
    }
    vector<int> depth(n+1,0);
    vector<int> low(n+1,0);
    vector<bool> bridge(m+1,0);
    function<void(int,int)> dfs1=[&](int a,int p)    
    {
        depth[a]=depth[p]+1;
        low[a]=depth[a];
        int u=0;
        for(auto [to,id]:v[a])
        {
            if(to==p) u=id;
            else if(depth[to]==0)
            {
                dfs1(to,a);
                low[a]=min(low[a],low[to]);
            }
            else low[a]=min(low[a],depth[to]);
        }
        if(p!=0&&low[a]==depth[a]) bridge[u]=1;
    };
    dfs1(1,0);
    vector<int> id(n+1,0);
    int bcc=0;
    function<void(int)> dfs2=[&](int a)
    {
        id[a]=bcc;
        for(auto [to,e]:v[a]) if(!bridge[e]&&id[to]==0) dfs2(to);
    };
    for(int i=1;i<=n;i++)
    {
        if(id[i]!=0) continue;
        bcc++;
        dfs2(i);
    }
    vector<int> sp(bcc+1,0);
    for(int i=1;i<=n;i++) sp[id[i]]|=special[i];
    set<array<int,2>> g[bcc+1];
    vector<int> d(bcc+1,0);
    for(int i=0;i<m;i++)
    {
        auto [a,b,w]=edges[i];
        if(!bridge[i+1]) continue;
        g[id[a]].insert({id[b],w});
        g[id[b]].insert({id[a],w});
        d[id[a]]++; d[id[b]]++;
    }
    vector<int> dsu_p(bcc+1,0);
    for(int i=1;i<=bcc;i++) dsu_p[i]=i;
    vector<int> dsu_sz(bcc+1,1);
    function<int(int)> find_set=[&](int a)->int
    {
        if(dsu_p[a]==a) return a;
        else return dsu_p[a]=find_set(dsu_p[a]);
    };
    auto merge_sets=[&](int a,int b)
    {
        a=find_set(a);
        b=find_set(b);
        dsu_p[b]=a;
        dsu_sz[a]+=dsu_sz[b];
    };
    queue<int> q;
    for(int i=1;i<=bcc;i++) if(d[i]==1&&!sp[i]) q.push(i);
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        auto [to,w]=(*g[a].begin());
        g[a].erase({to,w});
        g[to].erase({a,w});
        merge_sets(to,a);
        if((--d[to])==1&&!sp[to]) q.push(to);
    }
    vector<ll> csum(bcc+1,0);
    for(int i=1;i<=n;i++)
    {
        id[i]=find_set(id[i]);
        csum[id[i]]+=c[i];
    }
    vector<ll> dp(bcc+1,0);
    int root=find_set(1);
    function<void(int,int)> dfs3=[&](int a,int p)
    {
        dp[a]=csum[a];
        for(auto [to,w]:g[a])
        {
            if(to==p) continue;
            dfs3(to,a);
            dp[a]+=max(ll(0),dp[to]-w);
        }
    };
    dfs3(root,0);
    vector<ll> res(bcc+1,0);
    auto reroot=[&](int a,int b,int w) //b becomes root
    {
        dp[a]-=max(ll(0),dp[b]-w);
        dp[b]+=max(ll(0),dp[a]-w);
    };
    function<void(int,int)> dfs4=[&](int a,int p)
    {
        res[a]=dp[a];
        for(auto [to,w]:g[a])
        {
            if(to==p) continue;
            reroot(a,to,w);
            dfs4(to,a);
            reroot(to,a,w);
        }
    };
    dfs4(root,0);
    for(int i=1;i<=n;i++) cout << res[id[i]] << " \n"[i==n];
    return 0;
}