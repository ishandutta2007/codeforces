#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = (int) 1e9 + 7;

int add(int a, int b)
{
    a += b;
    if (a >= MOD)
    {
        return a - MOD;
    }
    if (a < 0)
    {
        return a + MOD;
    }
    return a;
}

int mul(int a, int b)
{
    return a * (ll) b % MOD;
}

int pw(int a, int b)
{
    int r = 1;
    while (b)
    {
        if (b & 1)
        {
            r = mul(r, a);
        }
        a = mul(a, a);
        b /= 2;
    }
    return r;
}

int dv(int a, int b)
{
    return mul(a, pw(b, MOD - 2));
}

const int N = 200000 + 7;
int val[N];
int q;
int tp[N];
int a[N];
int b[N];
int n = 1;
vector<int> g[N];
int ord[N];
int top;
int first[N];
int last[N];
bool vis[N];
int sz[N];
int par[N];

void dfs(int a)
{
    vis[a] = 1;
    ord[++top] = a;
    first[a] = top;
    for (auto &b : g[a])
    {
        if (vis[b] == 0)
        {
            dfs(b);
        }
    }
    last[a] = top;
}

int t[4 * N];
int lazy[4 * N];

void push(int v, int tl, int tr)
{
    if (lazy[v] != 1)
    {
        t[v] = mul(t[v], lazy[v]);
        if (tl < tr)
        {
            lazy[2 * v] = mul(lazy[2 * v], lazy[v]);
            lazy[2 * v + 1] = mul(lazy[2 * v + 1], lazy[v]);
        }
        lazy[v] = 1;
    }
}

void mult(int v, int tl, int tr, int l, int r, int x)
{
    push(v, tl, tr);
    if (tr < l || r < tl)
    {
        return;
    }
    if (l <= tl && tr <= r)
    {
        lazy[v] = mul(lazy[v], x);
        push(v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    mult(2 * v, tl, tm, l, r, x);
    mult(2 * v + 1, tm + 1, tr, l, r, x);
    t[v] = add(t[2 * v], t[2 * v + 1]);
}

void make(int v, int tl, int tr, int p, int x)
{
    push(v, tl, tr);
    if (tr < p || p < tl)
    {
        return;
    }
    if (tl == tr)
    {
        t[v] = x;
        return;
    }
    int tm = (tl + tr) / 2;
    make(2 * v, tl, tm, p, x);
    make(2 * v + 1, tm + 1, tr, p, x);
    t[v] = add(t[2 * v], t[2 * v + 1]);
}

int get(int v, int tl, int tr, int l, int r)
{
    push(v, tl, tr);
    if (tr < l || r < tl)
    {
        return 0;
    }
    if (l <= tl && tr <= r)
    {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return add(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

int smart(int x)
{
    x = par[x];
    if (x == 0)
    {
        return 1;
    }
    else
    {
        return dv(get(1, 1, n, first[x], first[x]), val[x]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> val[1] >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> tp[i];
        if (tp[i] == 1)
        {
            cin >> a[i] >> b[i];
            n++;
            val[n] = b[i];
            b[i] = n;
            par[n] = a[i];
            g[a[i]].push_back(n);
        }
        else
        {
            cin >> a[i];
        }
    }
    dfs(1);
    sz[1] = 1;
    make(1, 1, n, 1, val[1]);
    for (int i = 0; i < 4 * N; i++)
    {
        lazy[i] = 1;
    }
    for (int i = 1; i <= q; i++)
    {
        if (tp[i] == 1)
        {
            sz[a[i]]++;
            sz[b[i]] = 1;
            mult(1, 1, n, first[a[i]], last[a[i]], dv(sz[a[i]], sz[a[i]] - 1));
            make(1, 1, n, first[b[i]], mul(dv(get(1, 1, n, first[a[i]], first[a[i]]), val[a[i]]), val[b[i]]));
        }
        else
        {
            cout << dv(get(1, 1, n, first[a[i]], last[a[i]]), smart(a[i])) << "\n";
        }
    }
}