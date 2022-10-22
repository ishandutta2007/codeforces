#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, q, n, a[200005], tr[800005], tx[800005];

void build(int v, int l, int r)
{
    if(r - l == 1)
    {
        tr[v] = a[l];
        return;
    }

    int m = (l + r) / 2;

    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);

    tr[v] = tr[2 * v + 1] + tr[2 * v + 2];
}

int get(int v, int l, int r, int L, int R)
{
    if(L >= R)
        return 0;

    if(l == L && r == R)
        return tr[v];

    if(tx[v] != -1)
        return tx[v] * (R - L);

    int m = (l + r) / 2;

    return get(2 * v + 1, l, m, L, min(m, R)) + get(2 * v + 2, m, r, max(L, m), R);
}

void update(int v, int l, int r, int L, int R, int val)
{
    if(L >= R)
        return;

    if(l == L && r == R)
    {
        tx[v] = val;
        tr[v] = val * (r - l);
        return;
    }

    if(tx[v] != -1)
    {
        tx[2 * v + 1] = tx[v];
        tx[2 * v + 2] = tx[v];

        int m = (l + r) / 2;

        tr[2 * v + 1] = tx[v] * (m - l);
        tr[2 * v + 2] = tx[v] * (r - m);

        tx[v] = -1;
    }

    int m = (l + r) / 2;

    update(2 * v + 1, l, m, L, min(m, R), val);
    update(2 * v + 2, m, r, max(L, m), R, val);

    tr[v] = tr[2 * v + 1] + tr[2 * v + 2];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> q;

        string s, f;
        cin >> s >> f;

        for(int i = 0; i < n; i++)
            a[i] = f[i] - '0';

        for(int i = 0; i < 4 * n; i++)
            tx[i] = -1;

        build(0, 0, n);

        int l[q], r[q];

        for(int i = 0; i < q; i++)
        {
            cin >> l[i] >> r[i];
            l[i]--;
        }

        int F = 1;

        for(int i = q - 1; i >= 0; i--)
        {
            int x = get(0, 0, n, l[i], r[i]);

            if(x * 2 > r[i] - l[i])
                update(0, 0, n, l[i], r[i], 1);

            else if(x * 2 == r[i] - l[i])
                F = 0;

            else update(0, 0, n, l[i], r[i], 0);
        }

        for(int i = 0; i < n; i++)
            if(get(0, 0, n, i, i + 1) + '0' != s[i])
                F = 0;

        if(F)
            cout << "YES\n";
        else cout << "NO\n";
    }
}