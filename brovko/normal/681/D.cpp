#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew

using namespace std;

int n, m, a[100005], d[100005], used[100005], b[100005], p[100005];
vector <int> g[100005];

void dfs(int v)
{
    if(used[v])
        b[v] = v;

    if(a[v] != b[v])
    {
        cout << -1;
        exit(0);
    }

    for(auto to:g[v])
    {
        b[to] = b[v];
        d[to] = d[v] + 1;

        dfs(to);
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
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].push_back(v);
        p[v] = 1;
    }

    for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i]--;

            used[a[i]] = 1;
        }

    for(int i = 0; i < n; i++)
        if(p[i] == 0)
            dfs(i);

    vector <pair <int, int> > v;

    for(int i = 0; i < n; i++)
        if(used[i])
            v.push_back({d[i], i});

    sort(v.begin(), v.end());

    cout << (int)v.size() << "\n";

    for(int i = (int)v.size() - 1; i >= 0; i--)
        cout << v[i].second + 1 << "\n";
}