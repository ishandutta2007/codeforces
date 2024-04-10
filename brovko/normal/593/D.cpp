#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, m, u[200005], v[200005], x[200005], used[200005], p[200005], e[200005], pr[200005], tin[200005], tout[200005], T;
vector <int> g[200005];

void dfs(int v)
{
    used[v] = 1;
    tin[v] = ++T;

    for(auto to:g[v])
    {
        if(used[to] == 0)
        {
            p[to] = v;
            dfs(to);
        }
    }

    tout[v] = ++T;
}

int get(int x)
{
    if(x == pr[x])
        return x;

    pr[x] = get(pr[x]);
    return pr[x];
}

void unite(int x, int y)
{
    x = get(x);
    y = get(y);

    if(x == y)
        return;

    pr[x] = y;
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

    for(int i = 0; i < n - 1; i++)
    {
        cin >> u[i] >> v[i] >> x[i];

        u[i]--;
        v[i]--;

        g[u[i]].pb(v[i]);
        g[v[i]].pb(u[i]);
    }

    dfs(0);

    for(int i = 0; i < n - 1; i++)
    {
        if(u[i] == p[v[i]])
            e[v[i]] = x[i];
        else e[u[i]] = x[i];
    }

    for(int i = 0; i < n; i++)
        pr[i] = i;

    for(int i = 1; i < n; i++)
        if(e[i] == 1)
            unite(i, p[i]);

    while(m--)
    {
        int t;
        cin >> t;

        if(t == 1)
        {
            int a, b, y;
            cin >> a >> b >> y;

            a--;
            b--;

            a = get(a);
            b = get(b);

            while(y > 0 && !is_anc(a, b))
            {
                y /= e[a];
                a = get(p[a]);
            }

            while(y > 0 && !is_anc(b, a))
            {
                y /= e[b];
                b = get(p[b]);
            }

            cout << y << "\n";
        }
        else
        {
            int x, c;
            cin >> x >> c;
            x--;

            if(u[x] == p[v[x]])
            {
                e[v[x]] = c;

                if(c == 1)
                    unite(v[x], p[v[x]]);
            }
            else
            {
                e[u[x]] = c;

                if(c == 1)
                    unite(u[x], p[u[x]]);
            }
        }
    }
}