#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> g[n+1];
    vector<int> v[n+1];
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int q;
    cin >> q;
    vector<array<int,2>> queries(q+1,{0,0});
    vector<int> c(n+1,0);
    for(int i=1;i<=q;i++)
    {
        auto &[a,b]=queries[i];
        cin >> a >> b;
        c[a]^=1;
        c[b]^=1;
    }
    int cnt=0;
    for(int i=1;i<=n;i++) cnt+=c[i];
    vector<bool> vis(n+1,0);
    function<void(int)> dfs=[&](int a)
    {
        vis[a]=1;
        for(int to:g[a])
        {
            if(!vis[to])
            {
                v[a].push_back(to);
                v[to].push_back(a);
                dfs(to);
            }
        }
    };
    dfs(1);
    if(cnt==0)
    {
        cout << "YES\n";
        for(int i=1;i<=q;i++)
        {
            auto [x,y]=queries[i];
            vector<int> path={y};
            function<bool(int,int)> go=[&](int a,int p)->bool
            {
                if(a==y) return 1;
                for(int to:v[a])
                {
                    if(to==p) continue;
                    if(go(to,a))
                    {
                        path.push_back(a);
                        return 1;
                    }
                }
                return 0;
            };
            go(x,0);
            reverse(path.begin(),path.end());
            cout << path.size() << "\n";
            for(int a:path) cout << a << " ";
            cout << "\n";
        }
    }
    else
    {
        cout << "NO\n";
        cout << cnt/2 << "\n";
    }
    return 0;
}