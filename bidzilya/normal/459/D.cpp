#include <bits/stdc++.h>
using namespace std;

vector<int> t;

void Add(int v, int tl, int tr, int pos, int dx)
{
    t[v] += dx;
    if (tl != tr) {
        int tm = (tl + tr) >> 1;
        if (pos <= tm) {
            Add(2 * v, tl, tm, pos, dx);
        } else {
            Add(2 * v + 1, tm + 1, tr, pos, dx);
        }
    }
}

int Get(int v, int tl, int tr, int l, int r)
{
    if (tl == l && tr == r) {
        return t[v];
    } else {
        int tm = (tl + tr) >> 1;
        if (r <= tm) {
            return Get(2 * v, tl, tm, l, r);
        } else if (l > tm) {
            return Get(2 * v + 1, tm + 1, tr, l, r);
        } else {
            return Get(2 * v, tl, tm, l, tm) +
                   Get(2 * v + 1, tm + 1, tr, tm + 1, r);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<int, int> mp;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        ++mp[a[i]];
        p[i] = mp[a[i]];
    }
    mp.clear();
    vector<int> s(n);
    for (int i = n - 1; i >= 0; --i) {
        ++mp[a[i]];
        s[i] = mp[a[i]];
    }
    t.assign(4 * (n + 1), 0);
    Add(1, 0, n, s[n - 1], 1);
    long long ans = 0;
    for (int i = n - 2; i >= 0; --i) {
        ans += Get(1, 0, n, 0, p[i] - 1);
        Add(1, 0, n, s[i], 1);
    }
    cout << ans << endl;

    return 0;
}