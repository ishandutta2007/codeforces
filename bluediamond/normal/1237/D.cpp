#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 3e5 + 7;
int n;
int a[N];
int limit[N];
int tmin[4 * N];

void build(int v, int tl, int tr)
{
    if (tl == tr)
    {
        tmin[v] = a[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        tmin[v] = min(tmin[2 * v], tmin[2 * v + 1]);
    }
}

int get(int v, int tl, int tr, int l, int r)
{
    if (tr < l || r < tl)
    {
        return (int) 1e9;
    }
    if (l <= tl && tr <= r)
    {
        return tmin[v];
    }
    int tm = (tl + tr) / 2;
    return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

int get(int l, int r)
{
    return get(1, 1, n, l, r);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i + 2 * n] = a[i];
    }
    n *= 3;
    build(1, 1, n);
    for (int i = 1; i <= n; i++)
    {
        int x = a[i], l = i, r = n;
        limit[i] = i;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (get(i, m) >= (x + 1) / 2)
            {
                limit[i] = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = limit[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= n / 3; i++)
    {
        int l = i, r = n, last = i;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (get(i, m) >= m)
            {
                last = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        if (last == n)
        {
            cout << -1 << " ";
        }
        else
        {
            cout << last - i + 1 << " ";
        }
    }
    cout << "\n";
}