#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, dp[200005][2][2], p[200005], k[200005];
vector <int> g[200005];

void dfs(int v)
{
    for(auto to:g[v])
        if(to != p[v])
        {
            p[to] = v;
            dfs(to);
            k[v] += k[to];
        }

    if(k[v] == 0)
    {
        k[v] = 1;

        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                dp[v][i][j] = 1;

        return;
    }

    for(auto to:g[v])
        if(to != p[v])
            dp[v][0][0] = max(dp[v][0][0], dp[to][1][0] + k[v] - k[to]);

    dp[v][1][0] = 1;

    for(auto to:g[v])
        if(to != p[v])
            dp[v][1][0] += dp[to][0][0] - 1;

    dp[v][0][1] = k[v];

    for(auto to:g[v])
        if(to != p[v])
            dp[v][0][1] -= k[to] - dp[to][1][1];

    dp[v][1][1] = 1e9;

    for(auto to:g[v])
        if(to != p[v])
            dp[v][1][1] = min(dp[v][1][1], dp[to][0][1]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0);
    cout << dp[0][0][0] << ' ' << dp[0][0][1];
}