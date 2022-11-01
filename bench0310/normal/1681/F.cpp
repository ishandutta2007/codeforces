#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,2>> v[n+1];
    vector<array<int,3>> edges(n);
    vector<int> d(n,0);
    vector<int> sz(n+1,0);
    vector<int> depth(n+1,0);
    vector<int> tin(n+1,0);
    vector<int> tout(n+1,0);
    vector<int> h(n+1,0);
    int tcnt=0;
    vector<int> g[n+1];
    for(int i=1;i<=n-1;i++)
    {
        auto &[a,b,c]=edges[i];
        cin >> a >> b >> c;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
        g[c].push_back(i);
    }
    function<void(int,int)> dfs=[&](int a,int p)
    {
        depth[a]=depth[p]+1;
        sz[a]=1;
        tin[a]=(++tcnt);
        h[tcnt]=a;
        for(auto [to,i]:v[a])
        {
            if(to==p) continue;
            d[i]=to;
            dfs(to,a);
            sz[a]+=sz[to];
        }
        tout[a]=tcnt;
    };
    dfs(1,0);
    vector<int> up(n+1,0);
    vector<int> down(n+1,0);
    for(int i=1;i<=n;i++)
    {
        set<int> s;
        vector<int> ord;
        for(int j:g[i]) ord.push_back(d[j]);
        ranges::sort(ord,[&](int x,int y){return (depth[x]>depth[y]);});
        auto eval=[&](int a)
        {
            vector<int> tmp;
            down[a]=sz[a];
            while(1)
            {
                auto it=s.lower_bound(tin[a]);
                if(it!=s.end()&&(*it)<=tout[a])
                {
                    int b=h[*it];
                    tmp.push_back(b);
                    down[a]-=sz[b];
                    s.erase(it);
                }
                else break;
            }
            for(int b:tmp) up[b]=down[a];
            s.insert(tin[a]);
        };
        for(int a:ord) eval(a);
        eval(1);
    }
    ll res=0;
    for(int i=2;i<=n;i++) res+=(ll(down[i])*up[i]);
    cout << res << "\n";
    return 0;
}