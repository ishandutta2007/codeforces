#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, p[300005], siz[300005], a[300005], b[300005], pr[300005], tin[300005], tout[300005], T, used[300005];
vector <int> g[300005], g2[300005];

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

void dfs(int v)
{
    used[v] = 1;
    tin[v] = ++T;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            pr[to] = v;
            dfs(to);
        }
    }

    tout[v] = ++T;
}

bool is_anc(int x, int y)
{
    return (tin[x] <= tin[y] && tout[x] >= tout[y]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        p[i] = i;
        siz[i] = 1;
    }

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        if(get(u) != get(v))
        {
            g[u].pb(v);
            g[v].pb(u);
        }
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++)
    {
        cin >> a[i] >> b[i];

        a[i]--;
        b[i]--;

        g2[a[i]].pb(b[i]);
        g2[b[i]].pb(a[i]);
    }

    int k = 0;

    for(int i = 0; i < n; i++)
        if(g2[i].size() % 2)
            k++;

    if(k > 0)
    {
        cout << "NO\n" << k / 2;
        return 0;
    }

    cout << "YES\n";

    dfs(0);

    for(int i = 0; i < q; i++)
    {
        vector <int> v, u;

        while(!is_anc(a[i], b[i]))
        {
            v.pb(a[i]);
            a[i] = pr[a[i]];
        }

        while(a[i] != b[i])
        {
            u.pb(b[i]);
            b[i] = pr[b[i]];
        }

        u.pb(a[i]);
        reverse(u.begin(), u.end());

        cout << v.size() + u.size() << "\n";

        for(auto x:v)
            cout << x + 1 << ' ';

        for(auto x:u)
            cout << x + 1 << ' ';

        cout << "\n";
    }
}