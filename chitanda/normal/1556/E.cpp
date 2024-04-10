#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
const int M = 1000000007;
#define ls (t << 1)
#define rs ((t << 1) | 1)

const int maxn = 200005;
int n, q;
int a[maxn], b[maxn];
ll s[maxn];
ll v[maxn << 2];
ll mi[maxn << 2], ma[maxn << 2];

void build(int t, int l, int r) {
    if (l == r) {
        v[t] = mi[t] = ma[t] = b[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    mi[t] = min(mi[ls], v[ls] + mi[rs]);
    ma[t] = max(ma[ls], v[ls] + ma[rs]);
    v[t] = v[ls] + v[rs];
}

pair<ll, pair<ll, ll>> query(int t, int l, int r, int x, int y) {
    if (x <= l && y >= r) return make_pair(v[t], make_pair(mi[t], ma[t]));
    int mid = (l + r) >> 1;
    int res = 0;
    if (y <= mid) return query(ls, l, mid, x, y);
    if (x > mid) return query(rs, mid + 1, r, x, y);
    auto L = query(ls, l, mid, x, y), R = query(rs, mid + 1, r, x, y);
    return make_pair(L.fi + R.fi, make_pair(min(L.se.fi, L.fi + R.se.fi), max(L.se.se, L.fi + R.se.se)));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i], b[i] -= a[i], s[i] = s[i - 1] + b[i];

    build(1, 1, n);

    while (q--) {
        static int l, r;
        cin >> l >> r;
        if (s[r] - s[l - 1] != 0) {
            cout << "-1\n";
            continue;
        }

        auto res = query(1, 1, n, l, r);
        assert(res.fi == 0);
        if (res.se.fi < 0)
            cout << "-1\n";
        else
            cout << res.se.se << "\n";
    }
    return 0;
}