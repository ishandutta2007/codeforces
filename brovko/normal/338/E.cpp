#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
const int N = 5e5 + 5;

int t[4 * N], add[4 * N], y;

void push(int v, int l, int r)
{
    t[2 * v + 1] += add[v];
    t[2 * v + 2] += add[v];

    add[2 * v + 1] += add[v];
    add[2 * v + 2] += add[v];

    add[v] = 0;

    assert(t[v] == min(t[2 * v + 1], t[2 * v + 2]));
}

void update(int v, int l, int r, int L, int R, int val)
{
    if(L >= R)
        return;

//    cout << v << ' ' << l << ' ' << r << ' ' << L << ' ' << R << endl;

    if(L == l && R == r)
    {
        t[v] += val;
        add[v] += val;

        return;
    }

    int m = (l + r) / 2;
    push(v, l, r);

    update(2 * v + 1, l, m, L, min(m, R), val);
    update(2 * v + 2, m, r, max(L, m), R, val);

    t[v] = min(t[2 * v + 1], t[2 * v + 2]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, len, h;
    cin >> n >> len >> h;

    vector <int> b(len), a(n);

    for(int i = 0; i < len; i++)
        cin >> b[i];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector <int> c(len);

    for(int i = 0; i < len; i++)
        c[i] = h - b[i];

    vector <int> v;

    for(int i = 0; i < len; i++)
        v.pb(b[i]);

    for(int i = 0; i < n; i++)
        v.pb(a[i]);

    for(int i = 0; i < len; i++)
        v.pb(c[i]);

    sort(v.begin(), v.end());

    map <int, int> m;

    for(int i = 0; i < v.size(); i++)
    {
        if(i == 0 || v[i] != v[i - 1])
            m[v[i]] = ++y;
    }

    y++;

    for(int i = 0; i < len; i++)
        c[i] = m[c[i]];

    for(int i = 0; i < len; i++)
        b[i] = m[b[i]];

    for(int i = 0; i < n; i++)
        a[i] = m[a[i]];

//    cout << y << endl;
//
//    for(int i = 0; i < n; i++)
//        cout << a[i] << ' ';
//
//    for(int i = 0; i < n; i++)
//        cout << b[i] << ' ';
//
//    return 0;

    for(int i = 0; i < len; i++)
    {
        update(0, 0, y, 0, a[i] + 1, 1);
        update(0, 0, y, 0, c[i] + 1, -1);
    }

//    for(int i = 0; i < len; i++)
//        cout << b[i] << ' ';
//
//    cout << endl;
//
//    for(int i = 0; i < n; i++)
//        cout << a[i] << ' ';
//
//    cout << endl;
//
//    for(int i = 0; i < len; i++)
//        cout << c[i] << ' ';
//
//    cout << endl;

    int ans = 0;

    for(int i = len; i <= n; i++)
    {
        ans += (t[0] >= 0);

//        cout << t[0] << ' ';

        if(i < n)
        {
            update(0, 0, y, 0, a[i] + 1, 1);
            update(0, 0, y, 0, a[i - len] + 1, -1);
        }
    }

//    cout << endl;

    cout << ans;
}