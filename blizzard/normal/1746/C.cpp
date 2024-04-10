#include <bits/stdc++.h>

#ifdef LOCAL
#define err cerr
#else
#define err if (false) cerr
#endif

using namespace std;
using ll = long long;

using bs = bitset<200000>;

const int MAXN = 100000;

void solve() {
    int n;
    cin >> n;
//    int q; cin >> q;
    vector<int> a(n);
    vector<int> res(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> d(n, 0);
    vector<pair<int, int>> have;
    for (int i = 1; i < n; i++) {
        d[i] = a[i] - a[i - 1];
        if (d[i] < 0) {
            have.push_back({-d[i], i});
        }
    }
    sort(have.rbegin(), have.rend());
    for (int i = 1; i <= n and have.size() > 0; i++) {
        if (have.back().first > i) continue;
        res[i] = have.back().second;
        have.pop_back();
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] + 1 << " \n"[i == n];
    }

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}