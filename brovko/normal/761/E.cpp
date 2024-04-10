#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, d[35], x[35], y[35], z, used[35];
vector <int> g[35];

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            z /= 2;

            if(d[v] == 0)
            {
                d[v] = 1;
                d[to] = 3;
                x[to] = x[v];
                y[to] = y[v] + z;
            }

            else if(d[v] == 1)
            {
                d[v] = 2;
                d[to] = 0;
                x[to] = x[v] + z;
                y[to] = y[v];
            }

            else if(d[v] == 2)
            {
                d[v] = 3;
                d[to] = 1;
                x[to] = x[v];
                y[to] = y[v] - z;
            }

            else if(d[v] == 3)
            {
                d[v] = 0;
                d[to] = 2;
                x[to] = x[v] - z;
                y[to] = y[v];
            }

            dfs(to);
        }
    }
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

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0; i < n; i++)
    {
        if(g[i].size() > 4)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES\n";

    z = (1ll << n);
    dfs(0);

    for(int i = 0; i < n; i++)
    cout << x[i] << ' ' << y[i] << "\n";
}