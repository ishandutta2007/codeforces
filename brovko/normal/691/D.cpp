#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int n, m, a[1000005], used[1000005];
vector <int> g[1000005], c;

void dfs(int v)
{
    used[v] = 1;
    c.push_back(v);

    for(auto to:g[v])
        if(used[to] == 0)
            dfs(to);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0; i < n; i++)
        if(used[i] == 0)
        {
            c.clear();

            dfs(i);
            sort(c.begin(), c.end());

            vector <int> v;

            for(auto to:c)
                v.push_back(a[to]);

            sort(v.rbegin(), v.rend());

            for(int i = 0; i < c.size(); i++)
                a[c[i]] = v[i];
        }

    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
}