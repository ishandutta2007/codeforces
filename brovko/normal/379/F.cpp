#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int N = 1e6 + 43;

int q, v[N], d[N], p[N], up[N][20], tin[N], tout[N], T;
vector <int> g[N];

void dfs(int v)
{
    tin[v] = ++T;

    for(auto to:g[v])
    {
        p[to] = v;
        d[to] = d[v] + 1;
        dfs(to);
    }

    tout[v] = ++T;
}

bool is_anc(int u, int v)
{
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}

int lca(int x, int y)
{
    if(is_anc(x, y))
        return x;

    if(is_anc(y, x))
        return y;

    for(int i = 19; i >= 0; i--)
        if(!is_anc(up[x][i], y))
            x = up[x][i];

    return p[x];
}

int dist(int x, int y)
{
    return d[x] + d[y] - 2 * d[lca(x, y)];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n = 4;

    g[0] = {1, 2, 3};

    cin >> q;

    for(int i = 0; i < q; i++)
    {
        cin >> v[i];
        v[i]--;

        n += 2;

        g[v[i]].pb(n - 2);
        g[v[i]].pb(n - 1);
    }

    dfs(0);

    for(int i = 0; i < n; i++)
        up[i][0] = p[i];

    for(int j = 1; j < 20; j++)
        for(int i = 0; i < n; i++)
            up[i][j] = up[up[i][j - 1]][j - 1];

    n = 4;

    int a = 1, b = 2;

    for(int i = 0; i < q; i++)
    {
        n += 2;

        int x = dist(a, b), y = dist(a, n - 1), z = dist(b, n - 1);

        cout << max({x, y, z}) << "\n";

        if(x >= y && x >= z);
        else if(y >= x && y >= z)
            b = n - 1;
        else if(z >= x && z >= y)
            a = n - 1;
    }
}