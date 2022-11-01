#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<array<int,2>> v[n+1];
    vector<array<int,2>> edges;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
        edges.push_back({a,b});
    }
    vector<array<int,2>> r;
    for(int i=0;i<k;i++)
    {
        int a,b;
        cin >> a >> b;
        r.push_back({a,b});
    }
    const int inf=(1<<30);
    vector<vector<int>> d(n+1,vector<int>(n+1,inf));
    for(int o=1;o<=n;o++)
    {
        priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>> q;
        d[o][o]=0;
        q.push({0,o});
        while(!q.empty())
        {
            auto [da,a]=q.top();
            q.pop();
            if(d[o][a]<da) continue;
            for(auto [to,c]:v[a])
            {
                if(d[o][a]+c<d[o][to])
                {
                    d[o][to]=d[o][a]+c;
                    q.push({d[o][to],to});
                }
            }
        }
    }
    int res=inf;
    for(auto [x,y]:edges)
    {
        int now=0;
        for(auto [a,b]:r)
        {
            now+=min({d[a][b],d[a][x]+d[y][b],d[a][y]+d[x][b]});
        }
        res=min(res,now);
    }
    cout << res << "\n";
    return 0;
}