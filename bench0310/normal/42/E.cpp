#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<array<int,2>> v[N];
vector<int> depth(N,0);
vector<vector<int>> p(N,vector<int>(17,0));
vector<vector<int>> mx(N,vector<int>(17,0));

void dfs(int a)
{
    depth[a]=depth[p[a][0]]+1;
    for(int i=1;i<17;i++)
    {
        p[a][i]=p[p[a][i-1]][i-1];
        mx[a][i]=max(mx[a][i-1],mx[p[a][i-1]][i-1]);
    }
    for(auto [to,c]:v[a])
    {
        if(to==p[a][0]) continue;
        p[to][0]=a;
        mx[to][0]=c;
        dfs(to);
    }
}

int lca(int a,int b)
{
    if(depth[a]>depth[b]) swap(a,b);
    int res=0;
    for(int i=16;i>=0;i--)
    {
        if(depth[p[b][i]]>=depth[a])
        {
            res=max(res,mx[b][i]);
            b=p[b][i];
        }
    }
    if(a==b) return res;
    for(int i=16;i>=0;i--)
    {
        if(p[a][i]!=p[b][i])
        {
            res=max({res,mx[a][i],mx[b][i]});
            tie(a,b)={p[a][i],p[b][i]};
        }
    }
    return max({res,mx[a][0],mx[b][0]});
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<array<int,3>> edges(m);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        edges[i]={c,a,b};
    }
    sort(edges.begin(),edges.end());
    vector<int> par(n+1,0);
    vector<int> sz(n+1,1);
    for(int i=1;i<=n;i++) par[i]=i;
    function<int(int)> find_set=[&](int a)->int
    {
        if(a==par[a]) return a;
        else return par[a]=find_set(par[a]);
    };
    auto merge_sets=[&](int a,int b)->bool
    {
        a=find_set(a);
        b=find_set(b);
        if(a==b) return 0;
        if(sz[a]<sz[b]) swap(a,b);
        par[b]=a;
        sz[a]+=sz[b];
        return 1;
    };
    int cc=n;
    ll cost=0;
    for(auto [c,a,b]:edges)
    {
        if(merge_sets(a,b)==1)
        {
            cost+=c;
            cc--;
            v[a].push_back({b,c});
            v[b].push_back({a,c});
        }
    }
    dfs(1);
    int q;
    cin >> q;
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        if(cc==1) cout << cost-lca(a,b) << "\n";
        else if(cc==2)
        {
            if(find_set(a)!=find_set(b)) cout << cost << "\n";
            else cout << "-1\n";
        }
        else cout << "-1\n";
    }
    return 0;
}