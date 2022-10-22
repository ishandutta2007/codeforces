#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int t, n, m, p[100005], h[100005], f, used[100005], P[100005];
vector <int> g[100005];

void dfs(int v)
{
    used[v] = 1;

    int H = 0;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            dfs(to);

            H += h[to];
            P[v] += P[to];
        }
    }

    H -= p[v];

    if(H <= h[v] && (h[v] - H) % 2 == 0 && h[v] <= P[v]);
        else f = 0;
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
                cin >> p[i];
                P[i] = p[i];
            }

        for(int i = 0; i < n; i++)
            cin >> h[i];

        for(int i = 0; i < n; i++)
            {
                g[i].clear();
                used[i] = 0;
            }

        for(int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;

            u--;
            v--;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        f = 1;

        dfs(0);

        if(f)
            cout << "YES\n";
        else cout << "NO\n";
    }
}