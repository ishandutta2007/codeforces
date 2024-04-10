#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int n, a[200005], t[800005], b[200005], c[200005], t2[800005];

void update(int v, int l, int r, int pos, int val)
{
    if(r - l == 1)
    {
        t[v] = val;
        return;
    }

    int m = (l + r) / 2;

    if(pos < m)
        update(2 * v + 1, l, m, pos, val);
    else update(2 * v + 2, m, r, pos, val);

    t[v] = t[2 * v + 1] + t[2 * v + 2];
}

void upd2(int v, int l, int r, int pos, int val)
{
    if(r - l == 1)
    {
        t2[v] = val;
        return;
    }

    int m = (l + r) / 2;

    if(pos < m)
        upd2(2 * v + 1, l, m, pos, val);
    else upd2(2 * v + 2, m, r, pos, val);

    t2[v] = min(t2[2 * v + 1], t[2 * v + 1] + t2[2 * v + 2]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    vector <pair <int, int> > v;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        v.pb({a[i], i});
    }

    sort(v.rbegin(), v.rend());

    int ans = 0;

    for(auto to:v)
    {
        int y = to.y;
        b[y] = a[y];

        update(0, 0, n, y, a[y]);
        upd2(0, 0, n, y, a[y]);

        if(t2[0] < 0)
        {
            b[y] = 0;

            update(0, 0, n, y, 0);
            upd2(0, 0, n, y, 0);
        }
        else ans++;
    }

    cout << ans;
}