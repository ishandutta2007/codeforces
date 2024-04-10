#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, k, u, v, used[100005], d[100005], p[100005], st[100005];
vector <int> g[100005];
vector <pair <int, int> > c;
set <pair <int, int> > s;

bool comp(pair <int, int> x, pair <int, int> y)
{
    return (d[x.first] - d[x.second] < d[y.first] - d[y.second]);
}

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            d[to] = d[v] + 1;
            p[to] = v;
            dfs(to);
        }
        else if(to != p[v] && d[v] - d[to] <= k - 1 && d[v] > d[to])
        {
            c.push_back({v, to});
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0);

    sort(c.begin(), c.end());

    /*for(int i = 0; i < n; i++)
        cout << d[i] << ' ';
    cout << endl;*/

    if(c.size())
    {
        cout << "2\n";

        int v = c[0].first;
        int to = c[0].second;

        cout << d[v] - d[to] + 1 << "\n";

        cout << v + 1 << ' ';

        while(v != to)
        {
            v = p[v];
            cout << v + 1 << ' ';
        }

        return 0;
    }

    cout << "1\n";

    for(int i = 0; i < n; i++)
    {
        st[i] = g[i].size();
        s.insert({st[i], i});
    }

    for(int i = 0; i < (k + 1) / 2; i++)
    {
        pair <int, int> p = *s.begin();
        cout << p.second + 1 << ' ';
        s.erase(p);

        int v = p.second;
        st[v] = 1e18;

        for(auto to:g[v])
        {
            s.erase({st[to], to});
            st[to] = 1e18;

            for(auto to2:g[to])
                if(st[to2] < 1e17)
            {
                s.erase({st[to2], to2});
                s.insert({st[to2] - 1, to2});
                st[to2]--;
            }
        }
    }
}