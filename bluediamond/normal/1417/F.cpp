#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
const int M = (int) 3e5 + 7;
const int Q = (int) 5e5 + 7;
int n;
int m;
int q;
int val[N + M];
int a[M];
int b[M];
int type[Q];
int memo[Q];
int dsu[N + M];
bool use[M];
int node[Q];
vector<int> g[N + M];

int dsu_root(int x)
{
    if (dsu[x] == x)
    {
        return x;
    }
    else
    {
        return dsu[x] = dsu_root(dsu[x]);
    }
}

void unite(int x, int y)
{
    dsu[dsu_root(x)] = dsu_root(y);
}

void unite_edge(int i)
{
    int x = a[i];
    int y = b[i];
    if (dsu_root(x) != dsu_root(y))
    {
        g[i + n].push_back(dsu_root(x));
        g[i + n].push_back(dsu_root(y));
        unite(x, i + n);
        unite(y, i + n);
    }
}

int l[N + M];
int r[N + M];
int top;
int tree[4 * (N + M)];

int best(int i, int j)
{
    if (val[i] > val[j])
    {
        return i;
    }
    else
    {
        return j;
    }
}

void dfs(int a)
{
    l[a] = ++top;
    for (auto &b : g[a])
    {
        dfs(b);
    }
    r[a] = top;
}

void upd(int v, int tl, int tr, int i)
{
    if (tr < i || i < tl)
    {
        return;
    }
    if (tl == tr)
    {
        tree[v] = i;
        return;
    }
    int tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, i);
    upd(2 * v + 1, tm + 1, tr, i);
    tree[v] = best(tree[2 * v], tree[2 * v + 1]);
}

int get(int v, int tl, int tr, int l, int r)
{
    if (tr < l || r < tl)
    {
        return 0;
    }
    if (l <= tl && tr <= r)
    {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return best(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

void upd(int i, int x)
{
    val[i] = x;
    upd(1, 1, n + m, i);
}

int get(int l, int r)
{
    return get(1, 1, n + m, l, r);
}

bool poate[N + M];
int kek[N + M];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i];
        val[n + i] = -1;
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> type[i] >> memo[i];
        if (type[i] == 2)
        {
            use[memo[i]] = 1;
        }
    }
    for (int i = 1; i <= n + m; i++)
    {
        dsu[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        if (use[i] == 0)
        {
            unite_edge(i);
        }
    }
    for (int i = q; i >= 1; i--)
    {
        if (type[i] == 1)
        {
            node[i] = dsu_root(memo[i]);
        }
        else
        {
            unite_edge(memo[i]);
        }
    }
    for (int i = 1; i <= n + m; i++)
    {
        poate[i] = 1;
    }
    val[0] = -1;
    for (int i = 1; i <= n + m; i++)
    {
        for (auto &j : g[i])
        {
            poate[j] = 0;
        }
    }
    for (int i = 1; i <= n + m; i++)
    {
        if (poate[i])
        {
            g[n + m + 1].push_back(i);
        }
    }
    m++;
    dfs(n + m);
    for (int i = 1; i <= n + m; i++)
    {
        kek[i] = val[i];
    }
    for (int i = 1; i <= n + m; i++)
    {
        upd(l[i], kek[i]);
    }
    for (int i = 1; i <= q; i++)
    {
        if (type[i] == 1)
        {
            int k = get(l[node[i]], r[node[i]]);
            cout << val[k] << "\n";
            upd(k, 0);
        }
    }
}