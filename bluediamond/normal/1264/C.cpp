#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 998244353;

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

const int N = (int) 2e5 + 7;
int n;
int q;
int prod[N];

struct Data
{
    int prod;
    int val;
};

Data joint(Data a, Data b)
{
    if (a.prod == -1)
    {
        return b;
    }
    if (b.prod == -1)
    {
        return a;
    }
    int prod = mul(a.prod, b.prod);
    int val = add(a.val, mul(a.prod, b.val));
    return {prod, val};
}

Data t[4 * N];

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v].prod = prod[tl];
        t[v].val = prod[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        t[v] = joint(t[2 * v], t[2 * v + 1]);
    }
}

Data get(int v, int tl, int tr, int l, int r)
{
    if (tr < l || r < tl)
    {
        Data it;
        it.prod = -1;
        return it;
    }
    if (l <= tl && tr <= r)
    {
        return t[v];
    }
    else
    {
        int tm = (tl + tr) / 2;
        return joint(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
    }
}

int e(int l, int r)
{
    Data it = get(1, 1, n, l, r);
    int up = add(1, it.val);
    int down = it.prod;
    return add(dv(up, down), -1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> prod[i];
        prod[i] = dv(prod[i], 100);
    }
    build(1, 1, n);
    set<int> all;
    all.insert(1);
    all.insert(n + 1);
    int ans = e(1, n);
    while (q--)
    {
        int i;
        cin >> i;
        if (!all.count(i))
        {
            auto it = all.lower_bound(i);
            int p2 = *it;
            it--;
            int p1 = *it;
            ans = add(ans, -e(p1, p2 - 1));
            all.insert(i);
            ans = add(ans, e(p1, i - 1));
            ans = add(ans, e(i, p2 - 1));
        }
        else
        {
            all.erase(i);
            auto it = all.lower_bound(i);
            int p2 = *it;
            it--;
            int p1 = *it;
            ans = add(ans, -e(p1, i - 1));
            ans = add(ans, -e(i, p2 - 1));
            ans = add(ans, e(p1, p2 - 1));
        }
        cout << ans << "\n";
    }
}