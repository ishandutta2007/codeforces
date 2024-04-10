#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, w, a[1005], b[1005], c[1005], dp[1005][1005];
vector <int> g[1005], v[1005];

void dfs(int v, int x)
{
    c[v] = x;

    for(auto to:g[v])
        if(c[to] == 0)
            dfs(to, x);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> w;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        cin >> b[i];

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    int x = 1;

    for(int i = 0; i < n; i++)
    {
        if(c[i] == 0)
        {
            dfs(i, x);
            x++;
        }
    }

    for(int i = 0; i < n; i++)
    {
        v[c[i]].push_back(i);
    }

    int ans = 0;

    for(int i = 1; i < x; i++)
        for(int j = 0; j <= w; j++)
    {
        dp[i][j] = dp[i - 1][j];

        int A = 0;
        int B = 0;

        for(auto to:v[i])
        {
            if(j - a[to] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[to]] + b[to]);

            A += a[to];
            B += b[to];
        }

        if(j - A >= 0)
            dp[i][j] = max(dp[i][j], dp[i - 1][j - A] + B);

        ans = max(ans, dp[i][j]);
    }

    cout << ans;
}