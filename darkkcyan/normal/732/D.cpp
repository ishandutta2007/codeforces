#include <bits/stdc++.h>

using namespace std;

#define ve vector
#define xx first
#define yy second
#define long long long
#define sz(v) ((int)v.size())
#define bb begin()
#define ee end()
#define rbb rbegin()
#define ree rend()
typedef ve<int> vi;
typedef pair<int, int> ii;

int n, m;
vi d, a;
ve<ii> cnt;

bool ok(int x) {
    cnt.assign(m, ii(-1, -1));
    for (int i = x; i >= 0; --i) {
        if (d[i] == -1 or cnt[d[i]].xx != -1) continue;
        cnt[d[i]].xx = i;
        cnt[d[i]].yy = d[i];
    }
    sort(cnt.bb, cnt.ee);
    if (cnt[0].xx == -1) return false;
    int t = 0;
    for (int i = 0; i < m; ++i) {
        int exd = cnt[i].xx - i;
        int s = cnt[i].yy;
        if (exd < t + a[s]) return false;
        t += a[s];
    }
    return true;
}

int main() {
    #ifndef ONLINE_JUDGE
    #define filename "file"
    freopen(filename".inp", "r", stdin);
    freopen(filename".out", "w", stdout);
    #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    d.resize(n);
    for (int i = 0; i < n; ++i) cin >> d[i], --d[i];
    a.resize(m);
    for (int i = 0; i < m; ++i) cin >> a[i];

    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (ok(mid)) r = mid;
        else l = mid + 1;
    }

    if (!ok(l)) cout << -1;
    else cout << l + 1;

    return 0;
}