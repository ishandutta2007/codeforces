#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, used[300005], d[300005], d2[300005], L_x[300005], x[300005];
vector <int> g[300005];

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

        for(int i = 0; i < n; i++)
            used[i] = 0;

        d[0] = 0;
        dfs(0);

        for(int i = 0; i < n; i++)
            d2[i] = d[i];

        int u = 0;

        for(int i = 0; i < n; i++)
            if(d[i] > d[u])
                u = i;

        for(int i = 0; i < n; i++)
            used[i] = 0;

        d[u] = 0;
        dfs(u);

        for(int i = 0; i <= n + 1; i++)
            L_x[i] = -1e9;

        for(int j = 0; j < n; j++)
        {
            int D = (d[j] + 1) / 2;
            L_x[d2[j]] = max(D, L_x[d2[j]]);
        }

        for(int i = n - 1; i >= 0; i--)
            L_x[i] = max(L_x[i], L_x[i + 1]);

//        for(int i = 0; i <= n; i++)
//            cout << L_x[i] << ' ';
//
//        cout << "\n";

        for(int i = 0; i <= n; i++)
            x[i] = i - L_x[i + 1];

//        for(int i = 0; i <= n; i++)
//            cout << x[i] << ' ';
//
//        cout << "\n";

        for(int i = n - 1; i >= 0; i--)
            x[i] = min(x[i], x[i + 1]);

        int j = 1;

        for(int i = 1; i <= n; i++)
        {
            while(x[j] < i)
                j++;

            cout << j << ' ';
        }

        cout << "\n";
    }
}