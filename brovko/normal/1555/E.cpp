#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, t[4000005], tp[4000005], l[300005], r[300005], w[300005];

void push(int v, int l, int r)
{
    t[2 * v + 1] += tp[v];
    t[2 * v + 2] += tp[v];
    tp[2 * v + 1] += tp[v];
    tp[2 * v + 2] += tp[v];
    tp[v] = 0;
}

int get(int v, int l, int r, int L, int R)
{
    if(L >= R)
        return 1e9;

    if(l == L && r == R)
        return t[v];

    push(v, l, r);
    int m = (l + r) / 2;

    return min(get(2 * v + 1, l, m, L, min(m, R)), get(2 * v + 2, m, r, max(L, m), R));
}

void update(int v, int l, int r, int L, int R, int val)
{
    if(L >= R)
        return;

    if(L == l && R == r)
    {
        tp[v] += val;
        t[v] += val;
        return;
    }

    push(v, l, r);
    int m = (l + r) / 2;

    update(2 * v + 1, l, m, L, min(m, R), val);
    update(2 * v + 2, m, r, max(L, m), R, val);

    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    vector <pair <int, int> > v;

    for(int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i] >> w[i];
        v.pb({w[i], i});
    }

    sort(v.begin(), v.end());


    int R = 0, ans = 1e9;

    for(int L = 0; L < n; L++)
    {
        while(R < n && get(0, 0, m, 0, m - 1) == 0)
        {
            update(0, 0, m, l[v[R].y] - 1, r[v[R].y] - 1, 1);
            R++;
        }

//        cout << L << ' ' << R << ' ' << v[R - 1].x << ' ' << v[L].x << endl;

        if(get(0, 0, m, 0, m - 1) > 0)
            ans = min(ans, v[R - 1].x - v[L].x);

        update(0, 0, m, l[v[L].y] - 1, r[v[L].y] - 1, -1);
    }

    cout << ans;
}