#include <bits/stdc++.h>

using namespace std;

#define fn "main"
#define long long long
#define ve vector
#define xx first
#define yy second
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
#define sz(v) ((int) v.size())
#define inf(type) (numeric_limits<type>::max() - 10)
#define vi ve<int>
#define ii pair<int, int>

long n, m, k, x, s;
ve<long> a, b, c, d;

map<long, long> ma;

int main() {
    #ifndef ONLINE_JUDGE
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    cin >> n >> m >> k >> x >> s;
    a.resize(m); b = a;
    for (int i = 0; i < m; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    c.resize(k); d = c;
    for (int i = 0; i < k; ++i) cin >> c[i];
    for (int i = 0; i < k; ++i) cin >> d[i];

    long ans = n * x;

    for (int i = 0; i < m; ++i) {
        if (b[i] > s) continue;
        ans = min(ans,  n * a[i]);
        if (ma.count(b[i])) ma[b[i]] = min(ma[b[i]], a[i]);
        else ma[b[i]] = a[i];
    }

    if (ma.size() > 1)
    for (map<long, long>::iterator it = ma.bb, nxt = it; ++nxt != ma.ee; ++it) {
        nxt->yy = min(nxt->yy, it->yy);
    }

    for (int i = 0; i < k; ++i) {
        if (d[i] > s) continue;
        if (c[i] > n) {
            ans = 0;
            break;
        }
        ans = min(ans, (n - c[i]) * x);
        if (c[i] == n) break;
        map<long, long>::iterator it = ma.lower_bound(s - d[i]);
        if (it == ma.ee or it->xx > s - d[i]) {
            if (it == ma.bb) continue;
            --it;
        }
        ans = min(ans, (n - c[i]) * it->yy);
    }

    cout << ans;

    return 0;
}