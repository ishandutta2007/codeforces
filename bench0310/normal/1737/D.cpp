#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n,m;
        cin >> n >> m;
        vector<array<int,2>> v[n+1];
        vector<array<int,3>> edges(m);
        vector<int> opt(n+1,(1<<30));
        for(int i=1;i<=m;i++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            v[a].push_back({b,c});
            v[b].push_back({a,c});
            edges[i-1]={a,b,c};
            opt[a]=min(opt[a],c);
            opt[b]=min(opt[b],c);
        }
        auto bfs=[&](int s)->vector<int>
        {
            vector<int> d(n+1,-1);
            queue<int> q;
            auto add=[&](int a,int nd)
            {
                if(d[a]==-1)
                {
                    d[a]=nd;
                    q.push(a);
                }
            };
            add(s,0);
            while(!q.empty())
            {
                int a=q.front();
                q.pop();
                for(auto [to,c]:v[a]) add(to,d[a]+1);
            }
            return d;
        };
        vector<vector<int>> d(n+1);
        for(int i=1;i<=n;i++) d[i]=bfs(i);
        ll res=(1ll<<60);
        for(auto [a,b,c]:edges) res=min(res,ll(c)*min(d[1][a]+d[n][b]+1,d[1][b]+d[n][a]+1));
        for(int a=1;a<=n;a++)
        {
            for(int b=1;b<=n;b++)
            {
                res=min(res,ll(opt[b])*(d[a][b]+1+d[1][a]+d[a][n]+1));
            }
        }
        cout << res << "\n";
    }
    return 0;
}