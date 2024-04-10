#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;

int n, m, c[30][100005], col[30], even[100005], good[30][100005];
vector <int> g[30][100005];

void dfs(int j, int v)
{
    for(auto to:g[j][v])
    {
        if(c[j][to] == 0)
        {
            c[j][to] = c[j][v];
            dfs(j, to);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        u--;
        v--;

        for(int j = 0; j < 30; j++)
            if(w & (1 << j))
            {
                g[j][u].pb(v);
                g[j][v].pb(u);
            }

        if(w % 2 == 0)
        {
            even[v] = 1;
            even[u] = 1;
        }
    }

    for(int j = 0; j < 30; j++)
    {
        for(int i = 0; i < n; i++)
            if(c[j][i] == 0)
            {
                col[j]++;
                c[j][i] = col[j];
                dfs(j, i);
            }
    }

    for(int j = 0; j < 30; j++)
        for(int i = 0; i < n; i++)
            if(even[i])
                good[j][c[j][i]] = 1;

    int q;
    cin >> q;

    while(q--)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        int ans = 2;

        for(int j = 1; j < 30; j++)
            if(good[j][c[j][u]])
                ans = 1;

        for(int j = 0; j < 30; j++)
            if(c[j][u] == c[j][v])
                ans = 0;

        cout << ans << "\n";
    }
}