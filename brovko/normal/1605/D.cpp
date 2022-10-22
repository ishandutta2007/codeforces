#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, c[200005], p[200005], used[200005];
vector <int> g[200005];

void dfs(int v)
{
    for(auto to:g[v])
        if(c[to] == 0)
        {
            c[to] = 3 - c[v];
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

        for(int i = 0; i <= n; i++)
        {
            c[i] = 0;
            g[i].clear();
            p[i] = 0;
            used[i] = 0;
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

        c[0] = 1;
        dfs(0);

        vector <int> v1, v2;

        for(int i = 0; i < n; i++)
        {
            if(c[i] == 1)
                v1.pb(i);
            else v2.pb(i);
        }

        if(v1.size() > v2.size())
            swap(v1, v2);

        int k = v1.size();
        int x = 0;

        for(int i = 0; (1 << i) <= k; i++)
        {
            if(k & (1 << i))
            {
                for(int j = (1 << i); j < (1 << i + 1); j++)
                {
                    used[j] = 1;
                    p[v1[x++]] = j;
                }
            }
        }

        int y = 1;

        for(auto v:v2)
        {
            while(used[y])
                y++;

            used[y] = 1;
            p[v] = y;
        }

        for(int i = 0; i < n; i++)
            cout << p[i] << ' ';

        cout << "\n";
    }
}