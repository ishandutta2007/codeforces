#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template <typename T>
class fenwick
{
public:
    vector<T> fenw;
    int n;

    fenwick(int _n) : n(_n)
    {
        fenw.resize(n);
    }

    void modify(int x, T v)
    {
        while (x < n)
        {
            fenw[x] += v;
            x |= (x + 1);
        }
    }

    T get(int x)
    {
        T v{};
        while (x >= 0)
        {
            v += fenw[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
};

struct Tree
{
    vector<vector<int>> g;
    vector<int> sz, fa, son, dep, top, dfn;
    int dfncnt;
    Tree(int n) : g(n), sz(n), fa(n), son(n, -1), dep(n, 0), top(n), dfn(n)
    {
        dfncnt = 0;
    }
    void dfs1(int u, int par)
    {
        sz[u] = 1;
        fa[u] = par;
        for (auto v : g[u])
        {
            if (v == par)
                continue;
            dep[v] = dep[u] + 1;
            dfs1(v, u);
            sz[u] += sz[v];
            if (son[u] == -1 || sz[v] > sz[son[u]])
                son[u] = v;
        }
    }
    void dfs2(int u, int par, int tp)
    {
        dfn[u] = dfncnt++;
        top[u] = tp;
        if (son[u] != -1)
            dfs2(son[u], u, tp);
        for (auto v : g[u])
        {
            if (v == par || v == son[u])
                continue;
            dfs2(v, u, v);
        }
    }
    void init(int root)
    {
        dfs1(root, -1);
        dfs2(root, -1, root);
    }
    int lca(int x, int y)
    {
        while (top[x] != top[y])
        {
            if (dep[top[x]] < dep[top[y]])
                swap(x, y);
            x = fa[top[x]];
        }
        if (dep[x] > dep[y])
            swap(x, y);
        return x;
    }
    void add(int u, int l, fenwick<int> &fenw, int v)
    {
        while (top[u] != top[l])
        {
            fenw.modify(dfn[top[u]], v);
            fenw.modify(dfn[u] + 1, -v);
            u = fa[top[u]];
        }
        fenw.modify(dfn[l] + 1, v);
        fenw.modify(dfn[u] + 1, -v);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n;
    Tree tr(n);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        tr.g[u].push_back(v);
        tr.g[v].push_back(u);
    }
    tr.init(0);

    const int D = 20;
    vector<fenwick<int>> fenw(D + 1, fenwick<int>(n));
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int v;
            cin >> v;
            v--;
            int res = 0;
            for (int d = 0; d <= D; d++)
            {
                res += fenw[d].get(tr.dfn[v]);
                if (v == 0)
                    break;
                v = tr.fa[v];
            }
            cout << res << '\n';
        }
        else
        {
            int u, v, k, d;
            cin >> u >> v >> k >> d;
            u--, v--;
            int l = tr.lca(u, v);
            if (u != l)
                tr.add(u, l, fenw[d], k);
            if (v != l)
                tr.add(v, l, fenw[d], k);
            int now = d;
            for (int i = 0; i <= d; i++)
            {
                fenw[now].modify(tr.dfn[l], k);
                fenw[now].modify(tr.dfn[l] + 1, -k);
                if (now > 0)
                {
                    fenw[now - 1].modify(tr.dfn[l], k);
                    fenw[now - 1].modify(tr.dfn[l] + 1, -k);
                }
                if (l == 0)
                {
                    for (int j = now - 2; j >= 0; j--)
                    {
                        fenw[j].modify(tr.dfn[l], k);
                        fenw[j].modify(tr.dfn[l] + 1, -k);
                    }
                    break;
                }
                l = tr.fa[l];
                now -= 1;
            }
        }
    }

    return 0;
}