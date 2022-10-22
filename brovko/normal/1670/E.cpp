#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;

int n, used[1 << 17], d[1 << 17], ans[1 << 18], ptr;
vector <pair <int, int> > g[1 << 17];

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
    {
        if(used[to.y] == 0)
        {
            d[to.y] = d[v] + 1;

            if(d[v] % 2 == 0)
            {
                ans[n + to.x] = ptr + n;
                ans[to.y] = ptr;
                ptr++;
            }
            else
            {
                ans[n + to.x] = ptr;
                ans[to.y] = ptr + n;
                ptr++;
            }

            dfs(to.y);
        }
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
        int p;
        cin >> p;

        n = (1 << p);

        for(int i = 0; i < n; i++)
        {
            used[i] = 0;
            d[i] = 0;
            g[i].clear();
            ptr = 1;
        }

        for(int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;

            u--;
            v--;

            g[u].pb({i, v});
            g[v].pb({i, u});
        }

        dfs(0);
        ans[0] = n;

        cout << 1 << "\n";

        for(int i = 0; i < n; i++)
            cout << ans[i] << ' ';

        cout << "\n";

        for(int i = 0; i < n - 1; i++)
            cout << ans[i + n] << ' ';

        cout << "\n";
    }
}