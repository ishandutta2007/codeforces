#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct T
{
    int mn;
    int cmn;
};

T operator + (T a, T b)
{
    int mn = min(a.mn, b.mn);
    int cmn = a.cmn * (mn == a.mn) + b.cmn * (mn == b.mn);
    return {mn, cmn};
}

const int N = (int) 5e5 + 7;
T t[4 * N];
int lazy[4 * N];

void push(int v, int tl, int tr)
{
    if (lazy[v])
    {
        t[v].mn += lazy[v];
        if (tl < tr)
        {
            lazy[2 * v] += lazy[v];
            lazy[2 * v + 1] += lazy[v];
        }
        lazy[v] = 0;
    }
}

void add(int v, int tl, int tr, int l, int r, int x)
{
    push(v, tl, tr);
    if (tr < l || r < tl)
    {
        return;
    }
    if (l <= tl && tr <= r)
    {
        lazy[v] += x;
        push(v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    add(2 * v, tl, tm, l, r, x);
    add(2 * v + 1, tm + 1, tr, l, r, x);
    t[v] = t[2 * v] + t[2 * v + 1];
}

T get(int v, int tl, int tr, int l, int r)
{
    push(v, tl, tr);
    if (tr < l || r < tl)
    {
        return {(int) 1e9, 0};
    }
    if (l <= tl && tr <= r)
    {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return get(2 * v, tl, tm, l, r) + get(2 * v + 1, tm + 1, tr, l, r);
}

int n;
int a[N];
int l1[N];
int r1[N];
int l2[N];
int r2[N];
ll sol = 0;
vector<int> p[N];

void add(int l, int r, int x)
{
    add(1, 1, n, l, r, x);
}

T get(int l, int r)
{
    return get(1, 1, n, l, r);
}

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = {0, 1};
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = t[2 * v] + t[2 * v + 1];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    build(1, 1, n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--)
    {
        int x = a[i], sz;
        p[x].push_back(i);
        sz = (int) p[x].size();
        add(l1[x], r1[x], -1);
        if ((int) p[x].size() < 3)
        {
            l1[x] = p[x][sz - 1];
            r1[x] = n;
        }
        else
        {
            l1[x] = p[x][sz - 1];
            r1[x] = p[x][sz - 3] - 1;
        }
        add(l1[x], r1[x], +1);
        add(l2[x], r2[x], -1);
        if ((int) p[x].size() > 3)
        {
            l2[x] = p[x][sz - 4];
            r2[x] = n;
        }
        add(l2[x], r2[x], +1);
        T it = get(i, n);
        if (it.mn == 0)
        {
            sol += it.cmn;
        }
    }
    cout << sol << "\n";
}