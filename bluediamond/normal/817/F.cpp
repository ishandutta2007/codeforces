#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 1e5 + 7;
const int A = 2 * N;

bool inv[4 * A];
int val[4 * A];
int cnt[4 * A];

void push(int v, int tl, int tr)
{
    if (val[v] != -1)
    {
        cnt[v] = val[v] * (tr - tl + 1);
        if (tl < tr)
        {
            inv[2 * v] = inv[2 * v + 1] = 0;
            val[2 * v] = val[2 * v + 1] = val[v];
        }
        val[v] = -1;
        return;
    }
    if (inv[v])
    {
        cnt[v] = tr - tl + 1 - cnt[v];
        inv[v] = 0;
        if (tl < tr)
        {
            if (val[2 * v] != -1)
            {
                val[2 * v] ^= 1;
            }
            else
            {
                inv[2 * v] ^= 1;
            }
            if (val[2 * v + 1] != -1)
            {
                val[2 * v + 1] ^= 1;
            }
            else
            {
                inv[2 * v + 1] ^= 1;
            }
        }
        return;
    }
}

void make(int v, int tl, int tr, int l, int r, int x)
{
    push(v, tl, tr);
    if (tr < l || r < tl)
    {
        return;
    }
    if (l <= tl && tr <= r)
    {
        val[v] = x;
        push(v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    make(2 * v, tl, tm, l, r, x);
    make(2 * v + 1, tm + 1, tr, l, r, x);
    cnt[v] = cnt[2 * v] + cnt[2 * v + 1];
}

void invert(int v, int tl, int tr, int l, int r)
{
    push(v, tl, tr);
    if (tr < l || r < tl)
    {
        return;
    }
    if (l <= tl && tr <= r)
    {
        inv[v] = 1;
        push(v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    invert(2 * v, tl, tm, l, r);
    invert(2 * v + 1, tm + 1, tr, l, r);
    cnt[v] = cnt[2 * v] + cnt[2 * v + 1];
}

int get(int v, int tl, int tr, int p)
{
    push(v, tl, tr);
    if (p < tl)
    {
        return 0;
    }
    if (tr <= p)
    {
        return cnt[v];
    }
    int tm = (tl + tr) / 2;
    return get(2 * v, tl, tm, p) + get(2 * v + 1, tm + 1, tr, p);
}

int mex(int lim)
{
    int ans = lim + 1;
    int l = 1, r = lim;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (get(1, 1, lim, mid) < mid)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

int n;
int t[N];
ll l[N];
ll r[N];
set<ll> pts;
map<ll, int> trans;
ll invp[A];
int all;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    pts.insert(1);
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> l[i] >> r[i];
        pts.insert(l[i]);
        pts.insert(r[i] + 1);
    }
    for (auto &x : pts)
    {
        trans[x] = ++all;
        invp[all] = x;
    }

    for (int i = 1; i <= n; i++)
    {
        l[i] = trans[l[i]];
        r[i] = trans[r[i] + 1] - 1;
        if (t[i] == 1)
        {
            make(1, 1, all, l[i], r[i], 1);
        }
        if (t[i] == 2)
        {
            make(1, 1, all, l[i], r[i], 0);
        }
        if (t[i] == 3)
        {
            invert(1, 1, all, l[i], r[i]);
        }
        cout << invp[mex(all)] << "\n";
    }
}