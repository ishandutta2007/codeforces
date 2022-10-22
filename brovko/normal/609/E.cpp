#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, m, u[200005], v[200005], w[200005], p[200005], siz[200005], tin[200005], tout[200005], T, used[200005], up[200005][20], Max[200005][20];
vector <pair <int, int> > g[200005];
vector <vector <int> > e;

void dfs(int v)
{
    used[v] = 1;
    tin[v] = ++T;

    for(auto p:g[v])
    {
        int to = p.x;

        if(used[to] == 0)
        {
            up[to][0] = v;
            Max[to][0] = p.y;
            dfs(to);
        }
    }

    tout[v] = ++T;
}

bool is_anc(int x, int y)
{
    return (tin[x] <= tin[y] && tout[x] >= tout[y]);
}

int get(int x)
{
    if(x == p[x])
        return x;

    p[x] = get(p[x]);

    return p[x];
}

void unite(int x, int y)
{
    x = get(x);
    y = get(y);

    if(x == y)
        return;

    if(siz[x] > siz[y])
        swap(x, y);

    p[x] = y;
    siz[y] += siz[x];
}

void naive()
{
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            p[j] = j;
            siz[j] = 1;
        }

        unite(u[i], v[i]);
        int ans = w[i];

        for(auto to:e)
        {
            if(get(to[1]) != get(to[2]))
            {
                ans += to[0];
                unite(to[1], to[2]);
                g[to[1]].pb({to[2], to[0]});
                g[to[2]].pb({to[1], to[0]});
            }
        }

        cout << ans << "\n";
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
        cin >> u[i] >> v[i] >> w[i];

        u[i]--;
        v[i]--;

        e.pb({w[i], u[i], v[i]});
    }

    sort(e.begin(), e.end());

    for(int i = 0; i < n; i++)
    {
        p[i] = i;
        siz[i] = 1;
    }

    int ans = 0;

    for(auto to:e)
    {
        if(get(to[1]) != get(to[2]))
        {
            ans += to[0];
            unite(to[1], to[2]);
            g[to[1]].pb({to[2], to[0]});
            g[to[2]].pb({to[1], to[0]});
        }
    }

    dfs(0);

    for(int j = 1; j < 20; j++)
        for(int i = 0; i < n; i++)
        {
            up[i][j] = up[up[i][j - 1]][j - 1];
            Max[i][j] = max(Max[i][j - 1], Max[up[i][j - 1]][j - 1]);
        }

    for(int i = 0; i < m; i++)
    {
        int x = u[i], y = v[i], z = 0;

        for(int j = 19; j >= 0; j--)
        {
            if(!is_anc(up[x][j], y))
            {
                z = max(z, Max[x][j]);
                x = up[x][j];
            }
        }

        if(!is_anc(x, y))
        {
            z = max(z, Max[x][0]);
            x = up[x][0];
        }

        swap(x, y);

        for(int j = 19; j >= 0; j--)
        {
            if(!is_anc(up[x][j], y))
            {
                z = max(z, Max[x][j]);
                x = up[x][j];
            }
        }

        if(!is_anc(x, y))
        {
            z = max(z, Max[x][0]);
            x = up[x][0];
        }

        cout << ans - z + w[i] << "\n";
    }
}
/*
5 5
1 2 3
2 4 3
3 5 6
1 3 8
2 5 7

*/