#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, m, c[300005], F, k[3];
vector <pair <int, int> > g[200005];

void dfs(int v)
{
    for(auto to:g[v])
    {
        if(c[to.x] > 0 && (c[to.x] == c[v]) == to.y)
            F = 0;

        if(c[to.x] == 0)
        {
            if(to.y)
                c[to.x] = 3 - c[v];
            else c[to.x] = c[v];

            k[c[to.x]]++;

            dfs(to.x);
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
            c[i] = 0;
        }

        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;

            string s;
            cin >> s;

            u--;
            v--;

            int w = 0;

            if(s[0] == 'i')
                w = 1;

            g[u].pb({v, w});
            g[v].pb({u, w});
        }

        F = 1;
        int ans = 0;

        for(int i = 0; i < n; i++)
            if(c[i] == 0)
            {
                c[i] = 1;
                k[1] = 1;
                k[2] = 0;

                dfs(i);

                ans += max(k[1], k[2]);
            }

        if(F)
            cout << ans << "\n";
        else cout << "-1\n";
    }
}