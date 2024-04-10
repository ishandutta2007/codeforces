#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, a[300005], u, v, used[300005], p[300005], r[300005];
vector <pair <int, int> > g[300005];
vector <int> ans;

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
    {
        if(used[to.first] == 0)
            {
                p[to.first] = v;
                r[to.first] = to.second;

                dfs(to.first);
            }

    }

    if(p[v] != -1 && a[v] == 1)
        {
            a[v] = 0;

            if(a[p[v]] != -1)
                a[p[v]] ^= 1;

            ans.push_back(r[v]);
        }
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
        cin >> u >> v;
        u--;
        v--;

        g[u].push_back({v, i + 1});
        g[v].push_back({u, i + 1});
    }

    int x = -1;
    int k = 0;

    for(int i = 0; i < n; i++)
    {
        if(a[i] == -1)
            x = i;

        if(a[i] == 1)
            k++;
    }

    if(x == -1 && k % 2 != 0)
    {
        cout << -1;
        return 0;
    }

    for(int i = 0; i < n; i++)
        p[i] = -1;

    if(x == -1)
        dfs(0);
    else dfs(x);

    cout << ans.size() << "\n";

    for(auto to:ans)
        cout << to << ' ';
}