#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<array<int,3>> edges(m);
        for(auto &[a,b,c]:edges) cin >> a >> b >> c;
        int res=0;
        vector<int> v[n+1];
        for(int i=29;i>=0;i--)
        {
            vector<array<int,3>> now;
            for(auto [a,b,c]:edges) if((c&(1<<i))==0) now.push_back({a,b,c});
            for(auto [a,b,c]:now)
            {
                v[a].push_back(b);
                v[b].push_back(a);
            }
            vector<bool> vis(n+1,0);
            int c=0;
            function<void(int)> dfs=[&](int a)
            {
                vis[a]=1;
                c++;
                for(int to:v[a]) if(!vis[to]) dfs(to);
            };
            dfs(1);
            if(c==n) edges=now;
            else res+=(1<<i);
            for(int j=1;j<=n;j++) v[j].clear();
        }
        cout << res << "\n";
    }
    return 0;
}