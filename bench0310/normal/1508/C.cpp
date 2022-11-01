#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<array<int,2>> v[n+1];
    vector<array<int,3>> edges;
    int x=0;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if(a>b) swap(a,b);
        v[a].push_back({b,c});
        v[b].push_back({a,c});
        edges.push_back({a,b,c});
        x^=c;
    }
    ll cost=0;
    int zeroes_used=0;
    vector<bool> vis(n+1,0);
    set<int> unvis;
    for(int i=2;i<=n;i++) unvis.insert(i);
    queue<int> q;
    q.push(1);
    vis[1]=1;
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> pq;
    vector<array<int,2>> opt;
    for(int cnt=1;cnt<=n;cnt++)
    {
        if(q.empty())
        {
            assert(!pq.empty());
            while(vis[pq.top()[1]]==1) pq.pop();
            assert(!pq.empty());
            auto [da,a]=pq.top();
            pq.pop();
            cost+=da;
            q.push(a);
            vis[a]=1;
            unvis.erase(a);
        }
        int a=q.front();
        q.pop();
        vector<int> rm;
        for(auto [to,c]:v[a])
        {
            if(vis[to]==0)
            {
                unvis.erase(to);
                rm.push_back(to);
                pq.push({c,to});
            }
        }
        for(int b:unvis)
        {
            q.push(b);
            vis[b]=1;
            opt.push_back({min(a,b),max(a,b)});
            zeroes_used++;
        }
        unvis.clear();
        for(int b:rm) unvis.insert(b);
    }
    assert(unvis.empty());
    ll zeroes=(ll(n)*(n-1)/2-m);
    if(zeroes_used<zeroes)
    {
        cout << cost << "\n";
        exit(0);
    }
    int d[n+1][n+1];
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j]=0;
    for(auto [a,b,c]:edges) d[a][b]=c;
    vector<array<int,3>> kruskal;
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) kruskal.push_back({d[i][j],i,j});
    sort(kruskal.begin(),kruskal.end());
    ll res=(1ll<<60);
    vector<int> p(n+1,0);
    vector<int> sz(n+1,0);
    for(auto [bad_a,bad_b]:opt)
    {
        for(int i=1;i<=n;i++)
        {
            p[i]=i;
            sz[i]=1;
        }
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
        ll now=0;
        bool done=0;
        for(auto [c,a,b]:kruskal)
        {
            if(a==bad_a&&b==bad_b) continue;
            if(done==0&&c>x)
            {
                done=1;
                if(merge_sets(bad_a,bad_b)==1) now+=x;
            }
            if(merge_sets(a,b)==1) now+=c;
        }
        if(done==0&&merge_sets(bad_a,bad_b)==1) now+=x;
        res=min(res,now);
    }
    cout << res << "\n";
    return 0;
}