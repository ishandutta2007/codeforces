#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, a, b, da, db, d[100005], used[100005];
vector <int> g[100005];

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
        if(used[to] == 0)
        {
            d[to] = d[v] + 1;
            dfs(to);
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
        cin >> n >> a >> b >> da >> db;

        for(int i = 0; i < n; i++)
            g[i].clear();

        for(int i = 0; i < n - 1; i++)
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
            d[i] = 0;
        }

        dfs(0);

        int x = 0;

        for(int i = 0; i < n; i++)
            if(d[i] > d[x])
                x = i;

        for(int i = 0; i < n; i++)
        {
            used[i] = 0;
            d[i] = 0;
        }

        dfs(x);

        x = 0;

        for(int i = 0; i < n; i++)
            if(d[i] > x)
                x = d[i];

        for(int i = 0; i < n; i++)
        {
            used[i] = 0;
            d[i] = 0;
        }

        dfs(a - 1);

        if(db > 2 * da && x > 2 * da && d[b - 1] > da)
            cout << "Bob\n";
        else cout << "Alice\n";
    }
}