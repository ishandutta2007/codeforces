#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;

int n, used[300005], dp[300005], siz[300005];
vector <int> g[300005];

void dfs(int v)
{
    used[v] = 1;

    vector <int> c;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            c.pb(to);
            dfs(to);
            siz[v] += siz[to];
        }
    }

    siz[v]++;

    for(auto to:c)
    {
        dp[v] = max({dp[v], siz[to] - 1, dp[to] + siz[v] - siz[to] - 2});
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            used[i] = 0;
            g[i].clear();
            siz[i] = 0;
            dp[i] = 0;
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

        cout << dp[0] << "\n";
    }
}