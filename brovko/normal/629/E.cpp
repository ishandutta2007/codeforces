#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, kd[100005], sd[100005], used[100005], d[100005], tin[100005], tout[100005], T, up[100005][20], sall[100005], used2[100005];
vector <int> g[100005];

void dfs(int v)
{
    used[v] = 1;

    tin[v] = ++T;

    kd[v] = 1;
    sd[v] = d[v];

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            up[to][0] = v;

            d[to] = d[v] + 1;
            dfs(to);

            kd[v] += kd[to];
            sd[v] += sd[to];
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

    for(int i = 19; i >= 0; i--)
        if(!is_anc(up[u][i], v))
            u = up[u][i];

    return up[u][0];
}

int prelca(int u, int v)
{
    for(int i = 19; i >= 0; i--)
        if(!is_anc(up[v][i], u))
            v = up[v][i];

    return v;
}

void dfs2(int v)
{
    used2[v] = 1;

    for(auto to:g[v])
    {
        if(used2[to] == 0)
        {
            sall[to] = sall[v] - kd[to] + (n - kd[to]);
            dfs2(to);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

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

    sall[0] = sd[0];

    dfs2(0);

//    for(int i = 0; i < n; i++)
//        cout << sall[i] << ' ';
//
//    cout << endl;

    for(int j = 1; j < 20; j++)
        for(int i = 0; i < n; i++)
            up[i][j] = up[up[i][j - 1]][j - 1];

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        if(d[u] > d[v])
            swap(u, v);

        int dist = d[u] + d[v] - 2 * d[lca(u, v)];

        if(!is_anc(u, v))
        {
            int x = sd[u] - kd[u] * d[u];
            int y = sd[v] - kd[v] * d[v];

            cout << setprecision(20) << (ld)x / kd[u] + (ld)y / kd[v] + dist + 1 << "\n";
        }
        else
        {
            int y = sd[v] - kd[v] * d[v];

            int p = prelca(u, v);
            int x = sall[p] - (sd[p] - kd[p] * d[p]);

//            cout << "!" << p << ' ' << x << "\n";

            cout << setprecision(20) << (ld)x / (n - kd[p]) + (ld)y / kd[v] + dist << "\n";
        }
    }
}