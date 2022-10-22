#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, used[100005], siz[100005], d[100005], p[100005], up[100005][25], tin[100005], tout[100005], T;
vector <int> g[100005];

void dfs(int v)
{
    used[v] = 1;
    siz[v] = 1;
    tin[v] = ++T;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            p[to] = v;
            d[to] = d[v] + 1;
            dfs(to);
            siz[v] += siz[to];
        }
    }

    tout[v] = ++T;
}

bool is_anc(int u, int v)
{
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int u, int v)
{
    if(is_anc(u, v))
        return u;

    if(is_anc(v, u))
        return v;

    for(int j = 19; j >= 0; j--)
        if(!is_anc(up[u][j], v))
            u = up[u][j];

    return p[u];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0);

    for(int i = 0; i < n; i++)
        up[i][0] = p[i];

    for(int j = 1; j < 20; j++)
        for(int i = 0; i < n; i++)
            up[i][j] = up[up[i][j - 1]][j - 1];

    int q;
    cin >> q;

    while(q--)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        if(u == v)
        {
            cout << n << "\n";
            continue;
        }

        if(d[u] < d[v])
            swap(u, v);

        int x = lca(u, v);
        int L = d[u] + d[v] - 2 * d[x];

        if(L % 2)
        {
            cout << "0\n";
            continue;
        }

        L /= 2;

        int l = 0;

        for(int j = 19; j >= 0; j--)
            if(l + (1ll << j) < L)
            {
                u = up[u][j];
                l += (1ll << j);
            }

        if(d[v] - d[x] == L)
        {
            l = 0;

            for(int j = 19; j >= 0; j--)
                if(l + (1ll << j) < L)
                {
                    v = up[v][j];
                    l += (1ll << j);
                }

            cout << n - siz[v] - siz[u] << "\n";
        }
        else
        {
            cout << siz[p[u]] - siz[u] << "\n";
        }
    }
}