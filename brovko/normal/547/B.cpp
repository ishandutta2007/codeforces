#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[200005], p[200005], siz[200005], used[200005], ans, b[200005];

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
    siz[y] += siz[x];

    ans = max(ans, siz[y]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ans = 1;

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
    {
        p[i] = i;
        siz[i] = 1;
    }

    vector <pair <int, int> > v;

    for(int i = 0; i < n; i++)
    {
        v.pb({a[i], i});
    }

    sort(v.rbegin(), v.rend());

    for(auto p:v)
    {
        int i = p.y;

        used[i] = 1;

        if(used[i + 1])
            unite(i, i + 1);

        if(i > 0 && used[i - 1])
            unite(i, i - 1);

        b[ans] = max(b[ans], p.x);
    }

    for(int i = n - 1; i >= 1; i--)
        b[i] = max(b[i], b[i + 1]);

    for(int i = 1; i <= n; i++)
        cout << b[i] << ' ';
}