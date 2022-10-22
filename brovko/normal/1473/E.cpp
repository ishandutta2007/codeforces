#include <bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;
const ll INF = 1e18;

int n, m, used[1000005];
vector <pair <int, int> > g[1000005];
set <pair <ll, int> > s;
ll d[1000005], ans[1000005];

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

        if(v == 0)
            ans[u] = w;

        if(u == 0)
            ans[v] = w;

        g[u].push_back({v, w});
        g[v].push_back({u, w});

        g[u + n].push_back({v + n, w});
        g[v + n].push_back({u + n, w});

        g[u + 2 * n].push_back({v + 2 * n, w});
        g[v + 2 * n].push_back({u + 2 * n, w});

        g[u + 3 * n].push_back({v + 3 * n, w});
        g[v + 3 * n].push_back({u + 3 * n, w});

        g[u + 4 * n].push_back({v + 4 * n, w});
        g[v + 4 * n].push_back({u + 4 * n, w});

        g[u].push_back({v + n, 0});
        g[v].push_back({u + n, 0});

        g[u + n].push_back({v + 2 * n, 2 * w});
        g[v + n].push_back({u + 2 * n, 2 * w});

        g[u].push_back({v + 3 * n, 2 * w});
        g[v].push_back({u + 3 * n, 2 * w});

        g[u + 3 * n].push_back({v + 4 * n, 0});
        g[v + 3 * n].push_back({u + 4 * n, 0});
    }

    d[0] = 0;

    for(int i = 1; i < 5 * n; i++)
        d[i] = INF;

    for(int i = 0; i < 5 * n; i++)
        s.insert({d[i], i});

    while(!s.empty())
    {
        int v = (*s.begin()).second;

        for(auto to:g[v])
            if(used[to.first] == 0 && d[to.first] > d[v] + to.second)
            {
                s.erase({d[to.first], to.first});
                d[to.first] = d[v] + to.second;
                s.insert({d[to.first], to.first});
            }

        used[v] = 1;
        s.erase({d[v], v});
    }

    for(int i = 1; i < n; i++)
    {
        if(ans[i] == 0 || ans[i] > min(d[i + 2 * n], d[i + 4 * n]))
            ans[i] = min(d[i + 2 * n], d[i + 4 * n]);
    }

    for(int i = 1; i < n; i++)
        cout << ans[i] << ' ';
}

/*
5 4
1 2 1000000000
2 3 1000000000
3 4 1000000000
4 5 1000000000


*/