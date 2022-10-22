#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, k, p[1005], siz[1005], st[1005];

int get(int x)
{
    if(x == p[x])
        return x;

    p[x] = get(p[x]);
    return p[x];
}

void unite(int x, int y)
{
    x = get(x);
    y = get(y);

    if(x == y)
        return;

    if(st[x])
        swap(x, y);

    p[x] = y;
    siz[y] += siz[x];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
    {
        p[i] = i;
        siz[i] = 1;
    }

    for(int i = 0; i < k; i++)
    {
        int y;
        cin >> y;

        y--;
        st[y] = 1;
    }

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        unite(u, v);
    }

    int Max = -1;

    for(int i = 0; i < n; i++)
    {
        if(st[i] == 1 && (Max == -1 || siz[i] > siz[Max]))
            Max = i;
    }

    for(int i = 0; i < n; i++)
        if(st[get(i)] == 0)
            unite(i, Max);

    int ans = 0;

    for(int i = 0; i < n; i++)
        if(st[i])
    {
        ans += siz[i] * (siz[i] - 1) / 2;
    }

    ans -= m;

    cout << ans;
}