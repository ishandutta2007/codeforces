#include <bits/stdc++.h>
#define ll long long
#define null NULL

using namespace std;

const int mx = 6e5;
int n, t[4 * mx], a[mx], leaf[mx];

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void build(int v = 1, int tl = 0, int tr = n - 1) {
    if (tl == tr) {
        t[v] = a[tl];
        leaf[v] = 1;
    }
    else {
        int tm = (tl + tr) / 2;
        leaf[v] = 0;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = gcd(t[v * 2], t[v * 2 + 1]);
    }
}

void update(int pos, int val, int v = 1, int tl = 0, int tr = n - 1) {
    if (tl == tr)
        t[v] = val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(pos, val, v * 2, tl, tm);
        else
            update(pos, val, v * 2 + 1, tm + 1, tr);
        t[v] = gcd(t[v * 2], t[v * 2 + 1]);
    }
}

vector<int> segment_v;

void get(int l, int r, int v = 1, int tl = 0, int tr = n - 1) {
    if (l > r)
        return;
    if (l == tl && r == tr)
        segment_v.push_back(v);
    else {
        int tm = (tl + tr) / 2;
        get(l, min(r, tm), v * 2, tl, tm);
        get(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr);
    }
}

int cnt(int v, int x) {
    if (t[v] % x == 0)
        return 0;
    if (leaf[v] == 1)
        return 1;
    if (t[v * 2] % x == 0)
        return cnt(v * 2 + 1, x);
    if (t[v * 2 + 1] % x == 0)
        return cnt(v * 2, x);
    return 2;
}

int q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    build();
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int tp, l, r, x;
        cin >> tp;
        if (tp == 1) {
            segment_v.clear();
            cin >> l >> r >> x;
            l--;
            r--;
            get(l, r);
            int res = 0;
            for (int i = 0; i < segment_v.size(); ++i) {
                res += cnt(segment_v[i], x);
            }
            if (res <= 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else {
            cin >> l >> r;
            l--;
            update(l, r);
        }
    }
    return 0;
}