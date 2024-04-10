#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[100005], t[400005][60];

void build(int v, int l, int r)
{
    if(r - l == 1)
    {
        for(int i = 0; i < 60; i++)
            t[v][i] = 1;

        for(int i = 0; i < 60; i += a[l])
            t[v][i] = 2;

        return;
    }

    int m = (l + r) / 2;

    build(2 * v + 1, l, m);
    build(2 * v + 2, m, r);

    for(int i = 0; i < 60; i++)
        t[v][i] = t[2 * v + 1][i] + t[2 * v + 2][(i + t[2 * v + 1][i]) % 60];
}

int get(int v, int l, int r, int L, int R, int i)
{
    if(L >= R)
        return 0;

    if(L == l && R == r)
        return t[v][i];

    int m = (l + r) / 2;

    int T = get(2 * v + 1, l, m, L, min(m, R), i);
    i = (i + T) % 60;

    return T + get(2 * v + 2, m, r, max(L, m), R, i);
}

void update(int v, int l, int r, int pos, int val)
{
    if(r - l == 1)
    {
        a[l] = val;

        for(int i = 0; i < 60; i++)
            t[v][i] = 1;

        for(int i = 0; i < 60; i += val)
            t[v][i] = 2;

        return;
    }

    int m = (l + r) / 2;

    if(pos < m)
        update(2 * v + 1, l, m, pos, val);
    else update(2 * v + 2, m, r, pos, val);

    for(int i = 0; i < 60; i++)
        t[v][i] = t[2 * v + 1][i] + t[2 * v + 2][(i + t[2 * v + 1][i]) % 60];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    build(0, 0, n);

    int q;
    cin >> q;

    while(q--)
    {
        char c;
        int x, y;
        cin >> c >> x >> y;

        if(c == 'A')
            cout << get(0, 0, n, x - 1, y - 1, 0) << "\n";
        else update(0, 0, n, x - 1, y);
    }
}