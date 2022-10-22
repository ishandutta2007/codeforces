#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;
typedef long long ll;

const ll INF = 1e16;

ll dt[502][502];
ll u[250002], v[250002], w[250002];
vector<int> adj[502];

void solve()
{
    int n, m; cin >> n >> m;
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=m;i++)
    {
        cin >> u[i] >> v[i] >> w[i];
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }
    
    for(int S=1;S<=n;S++)
    {
        queue<int> q;
        for(int i=1;i<=n;i++) dt[S][i] = INF;
        dt[S][S] = 0; q.push(S);
        
        while(!q.empty())
        {
            int now = q.front(); q.pop();
            for(int i : adj[now])
            {
                if(dt[S][i] > dt[S][now] + 1) {
                    dt[S][i] = dt[S][now] + 1;
                    q.push(i);
                }
            }
        }
    }
    ll ans = INF;
    for(int i=1;i<=m;i++)
    {
        ll a = u[i], b = v[i], c = w[i];
        ll len = dt[1][a] + dt[n][b] + 1;
        len = min(len, dt[1][b] + dt[n][a] + 1);
        for(int j=1;j<=n;j++) len = min(len, min(dt[a][j], dt[b][j]) + dt[1][j] + dt[n][j] + 2);
        
        ans = min(ans, len * c);
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--)
    {
        solve();
    }
}