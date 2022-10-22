#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int t, n, m, used[300005], c[300005];
vector <int> g[300005];

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            used[to] = 1;
            c[to] = 1;

            for(auto x:g[to])
                used[x] = 1;

            for(auto x:g[to])
                dfs(x);
        }
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
            used[i] = 0;
            c[i] = 0;
            g[i].clear();
        }

        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;

            u--;
            v--;

            g[u].pb(v);
            g[v].pb(u);
        }

        dfs(0);

        int F = 1;

        for(int i = 0; i < n; i++)
            if(used[i] == 0)
                F = 0;

        if(F == 0)
            cout << "NO\n";
        else
        {
            cout << "YES\n";

            int ans = 0;

            for(int i = 0; i < n; i++)
                ans += c[i];

            cout << ans << "\n";

            for(int i = 0; i < n; i++)
                if(c[i])
                    cout << i + 1 << ' ';

            cout << "\n";
        }
    }
}