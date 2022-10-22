#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, U[100005], V[100005], d[100005], used[100005];
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
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            g[i].clear();
            d[i] = 0;
            used[i] = 0;
        }

        for(int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;

            u--;
            v--;

            U[i] = u;
            V[i] = v;

            g[u].pb(v);
            g[v].pb(u);
        }

        int x = -1, y = -1;

        for(int i = 0; i < n; i++)
        {
            if(g[i].size() <= 1)
                x = i;

            if(g[i].size() > 2)
                y = i;
        }

        if(y > -1)
        {
            cout << -1 << "\n";
            continue;
        }

        dfs(x);

        for(int i = 0; i < n - 1; i++)
        {
            if(min(d[U[i]], d[V[i]]) % 2 == 0)
                cout << 2 << ' ';
            else cout << 3 << ' ';
        }

        cout << "\n";
    }
}