#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, m, d[200005], dp[200005], used[200005];
vector <int> g[200005];

void dfs(int v)
{
    used[v] = 1;
    dp[v] = d[v];

    for(auto to:g[v])
    {
        if(used[to] == 0 && d[to] > d[v])
            dfs(to);

        if(d[to] > d[v])
            dp[v] = min(dp[v], dp[to]);
        else dp[v] = min(dp[v], d[to]);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(int i = 0; i < n; i++)
        {
            g[i].clear();
            used[i] = 0;
            dp[i] = 0;
            d[i] = 0;
        }

        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;

            u--;
            v--;

            g[u].pb(v);
        }

        queue <int> q;

        for(int i = 1; i < n; i++)
            d[i] = 1e9;

        d[0] = 0;
        q.push(0);

        while(!q.empty())
        {
            int v = q.front();
            q.pop();

            for(auto to:g[v])
                if(d[to] > 1e8)
                {
                    d[to] = d[v] + 1;
                    q.push(to);
                }
        }

        dfs(0);

        for(int i = 0; i < n; i++)
            cout << dp[i] << ' ';

        cout << "\n";
    }
}