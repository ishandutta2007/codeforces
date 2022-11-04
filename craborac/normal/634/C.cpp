#include <bits/stdc++.h>

using namespace std;

long long a[(int)2e5 * 4 + 10];
long long b[(int)2e5 * 4 + 10];
long long c[(int)2e5 * 4 + 10];
long long A, B;

void init(int v, int l, int r)
{
    a[v] = 0;
    b[v] = 0;
    c[v] = 0;
    if (r - l > 1)
    {
        int m = (l + r) / 2;
        init(2 * v + 1, l, m);
        init(2 * v + 2, m, r);
    }
}

long long s1(int v, int l, int r, int q, int w)
{
    if (q == w)
        return 0;
    if (r <= q || l >= w)
        return 0;
    if (q <= l && r <= w)
        return a[v];
    int m = (l + r) / 2;
    return s1(2 * v + 1, l, m, q, w) + s1(2 * v + 2, m, r, q, w);
}

long long s2(int v, int l, int r, int q, int w)
{
    if (q == w)
        return 0;
    if (r <= q || l >= w)
        return 0;
    if (q <= l && r <= w)
        return b[v];
    int m = (l + r) / 2;
    return s2(2 * v + 1, l, m, q, w) + s2(2 * v + 2, m, r, q, w);
}

void ins(int v, int l, int r, int q, long long s)
{
    //cout << v << " " << l << " " << r << endl;
    if (r - l == 1)
    {
        c[v] += s;
        a[v] = min(A, c[v]);
        b[v] = min(B, c[v]);
        return;
    }
    int m = (l + r) / 2;
    if (q < m)
        ins(2 * v + 1, l, m, q, s);
    else
        ins(2 * v + 2, m, r, q, s);
    a[v] = a[2 * v + 1] + a[2 * v + 2];
    b[v] = b[2 * v + 1] + b[2 * v + 2];
}

int main()
{
    int n, k, q;
    cin >> n >> k >> A >> B >> q;
    n++;
    init(0, 0, n);
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int y;
            long long z;
            cin >> y >> z;
            ins(0, 0, n, y, z);
        }
        else
        {
            int y;
            cin >> y;
            cout << s2(0, 0, n, 0, y) + s1(0, 0, n, y + k, n) << endl;
        }
    }
    return 0;
}