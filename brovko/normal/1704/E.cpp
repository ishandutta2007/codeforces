#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;

using li = long long;
const int MOD = 998244353;

vector <int> g[1005], ts;
int used[1005], d[1005], dp[1005];

int add(int x, int y)
{
    x += y;

    while(x >= MOD)
        x -= MOD;

    return x;
}

int mul(int x, int y)
{
    return x * 1ll * y % MOD;
}

void dfs(int v)
{
    used[v] = 1;
    d[v] = 1e9;

    dp[v] = 0;

    for(auto to:g[v])
    {
        if(used[to] == 0)
            dfs(to);

        d[v] = min(d[v], d[to] + 1);
        dp[v] = add(dp[v], dp[to]);
    }

    if(g[v].size() == 0)
        d[v] = 0, dp[v] = 1;

    ts.pb(v);
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
        int n, m;
        cin >> n >> m;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
        {
            g[i].clear();
            used[i] = 0;
        }

        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;

            u--;
            v--;

            g[u].pb(v);
        }

        ts.clear();

        for(int i = 0; i < n; i++)
            if(used[i] == 0)
                dfs(i);

        int ans = 0;

        for(int i = 0; i < n; i++)
            ans = add(ans, mul(a[i], dp[i]));

        int x = 0;

        while(g[x].size())
            x++;

        for(int i = 0; i < n; i++)
        {
            if(a[x] == 0)
                ans = add(ans, 1);

            bool F = 1;

            for(int j = 0; j < n; j++)
                if(a[ts[j]] > 0)
                {
                    a[ts[j]]--;

                    for(auto to:g[ts[j]])
                        a[to]++;

                    F = 0;
                }

            if(F)
            {
                ans = i;
                break;
            }
        }

//        for(int i = 0; i < n; i++)
//            if(cnt[i] <= i)
//                ans = add(ans, 1);

        cout << ans << "\n";
    }
}