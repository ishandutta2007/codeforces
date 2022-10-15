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

const int N = (int) 1e6 + 7;
int dp[N];

int dumb(int n, int k)
{
    int all = 1, good = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 0;
        int l = max(1, i - k), r = i - 1;
        for (int j = l; j <= r; j++)
        {
            dp[i] = add(dp[i], dp[j]);
        }
        for (int j = 1; j < i; j++)
        {
            dp[j] = mul(dp[j], (i - 1));
        }
    }
    for (int i = 1; i <= n; i++)
    {
        all = mul(all, i);
        good = add(good, dp[i]);
    }
    return add(all, -good);
}

int t[4 * N];
int mlt[4 * N];

void push(int v, int tl, int tr)
{
    if (mlt[v] != 1)
    {
        if (tl < tr)
        {
            mlt[2 * v] = mul(mlt[2 * v], mlt[v]);
            mlt[2 * v + 1] = mul(mlt[2 * v + 1], mlt[v]);
        }
        t[v] = mul(t[v], mlt[v]);
        mlt[v] = 1;
    }
}

void upd(int v, int tl, int tr, int l, int r, int x)
{
    push(v, tl, tr);
    if (tr < l || r < tl)
    {
        return;
    }
    if (l <= tl && tr <= r)
    {
        mlt[v] = mul(mlt[v], x);
        push(v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, l, r, x);
    upd(2 * v + 1, tm + 1, tr, l, r, x);
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

int smart(int n, int k)
{
    for (int i = 1; i <= 4 * n; i++)
    {
        t[i] = 0;
        mlt[i] = 1;
    }
    make(1, 1, n, 1, 1);
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 0;
        int l = max(1, i - k), r = i - 1;
        make(1, 1, n, i, get(1, 1, n, l, r));
        upd(1, 1, n, 1, i - 1, (i - 1));
    }
    int all = 1;
    for (int i = 1; i <= n; i++)
    {
        all = mul(all, i);
    }
    int good = get(1, 1, n, 1, n);
    return add(all, -good);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    cout << smart(n, k) << "\n";
}