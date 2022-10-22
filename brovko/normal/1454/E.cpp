#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, used[200005], p[200005], f, used2[200005], dp[200005];
vector <int> g[200005];

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
    {
        if(used[to] != 0 && p[v] != to && f == 0)
        {
            f = 1;

            used[v] = 2;

            while(v != to)
            {
                v = p[v];
                used[v] = 2;
            }
        }

        if(used[to] == 0)
        {
            p[to] = v;
            dfs(to);
        }
    }
}

void dfs2(int v)
{
    used2[v] = 1;

    for(auto to:g[v])
        if(used2[to] == 0 && used[to] < 2)
    {
        dfs2(to);
        dp[v] += dp[to];
    }

    dp[v]++;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        f = 0;

        cin >> n;

        for(int i = 0; i < n; i++)
            g[i].clear();

        for(int i = 0; i < n; i++)
        {
            int u, v;
            cin >> u >> v;

            u--;
            v--;

            g[u].pb(v);
            g[v].pb(u);
        }

        for(int i = 0; i < n; i++)
        {
            used[i] = 0;
            used2[i] = 0;
            dp[i] = 0;
        }

        dfs(0);

        int ans = n * (n - 1);

        for(int i = 0; i < n; i++)
            if(used[i] == 2)
        {
            dfs2(i);
            ans += dp[i] * (n - dp[i]);
        }

        cout << ans / 2 << "\n";
    }
}