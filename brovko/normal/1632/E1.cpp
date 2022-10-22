#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, used[3005], d[3005][3005], L_x[3005], x[3005];
vector <int> g[3005];

void dfs(int first, int v)
{
    used[v] = 1;

    for(auto to:g[v])
        if(used[to] == 0)
        {
            d[first][to] = d[first][v] + 1;
            dfs(first, to);
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
        {
            for(int j = 0; j < n; j++)
                used[j] = 0;

            d[i][i] = 0;
            dfs(i, i);
        }

        for(int i = 0; i <= n + 1; i++)
            L_x[i] = -1e9;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                int D = (d[i][j] + 1) / 2;
                L_x[min(d[0][i], d[0][j])] = max(D, L_x[min(d[0][i], d[0][j])]);
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

        for(int i = 1; i <= n; i++)
        {
            int j = 1;

            while(x[j] < i)
                j++;

            cout << j << ' ';
        }

        cout << "\n";
    }
}