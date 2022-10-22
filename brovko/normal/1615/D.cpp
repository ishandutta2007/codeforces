#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, m, used[200005], c[200005], F;
vector <pair <int, int> > g[200005], g2[200005];

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g2[v])
    {
        if(used[to.x] == 0)
        {
            c[to.x] = (c[v] ^ to.y);
            dfs(to.x);
        }
        else if(c[to.x] != (c[v] ^ to.y))
        {
            F = 0;
//            cout << "!" << v << ' ' << to.x << endl;
//            exit(0);
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
            g[i].clear();
            g2[i].clear();
            used[i] = 0;
            c[i] = 0;
        }

        F = 1;

        for(int i = 0; i < n - 1; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;

            u--;
            v--;

            g[u].pb({v, w});
            g[v].pb({u, w});

            if(w != -1)
                w = __builtin_popcount(w) % 2;

            if(w != -1)
            {
                g2[u].pb({v, w});
                g2[v].pb({u, w});
            }
        }

        for(int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;

            u--;
            v--;

            g2[u].pb({v, w});
            g2[v].pb({u, w});
        }

        for(int i = 0; i < n; i++)
            if(used[i] == 0)
                dfs(i);

        if(F == 0)
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        for(int i = 0; i < n; i++)
        {
            for(auto to:g[i])
                if(to.x > i)
                {
                    cout << i + 1 << ' ' << to.x + 1 << ' ';

                    if(to.y != -1)
                        cout << to.y << "\n";
                    else
                    if(c[to.x] == c[i])
                        cout << "0\n";
                    else cout << "1\n";
                }
        }
    }
}