#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define li long long

using namespace std;

int n, d, p[1005], siz[1005], k[1005];

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

    if(siz[x] > siz[y])
        swap(x, y);

    p[x] = y;

    k[siz[x]]--;
    k[siz[y]]--;

    siz[y] += siz[x];

    k[siz[y]]++;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d;

    int cnt = 1;

    for(int i = 0; i < n; i++)
    {
        p[i] = i;
        siz[i] = 1;
    }

    k[1] = n;

    for(int i = 0; i < d; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        if(get(u) == get(v))
            cnt++;

        unite(u, v);

        int c = 0;
        int ans = 0;

        for(int i = n; i >= 0; i--)
        {
            int x = min(cnt - c, k[i]);
            c += x;
            ans += x * i;
        }

        cout << ans - 1 << "\n";
    }
}