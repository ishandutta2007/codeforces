#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

int t, n, l[100005], r[100005], used[100005], dp[100005][2];
vector <int> g[100005];

void dfs(int v)
{
    dp[v][0] = 0;
    dp[v][1] = 0;

    used[v] = 1;

    for(auto to:g[v])
        if(used[to] == 0)
        {
            dfs(to);

            dp[v][0] += max(dp[to][0] + abs(l[v] - l[to]), dp[to][1] + abs(l[v] - r[to]));
            dp[v][1] += max(dp[to][0] + abs(r[v] - l[to]), dp[to][1] + abs(r[v] - r[to]));
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
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> l[i] >> r[i];

        for(int i = 0; i < n; i++)
        {
            used[i] = 0;
            g[i].clear();
        }

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

        cout << max(dp[0][0], dp[0][1]) << "\n";
    }
}