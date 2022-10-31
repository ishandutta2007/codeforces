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
    int n, k;
    cin >> n >> k;
//    int q; cin >> q;
    vector<int> a(n);
    vector<int> res(n + 1, 0);

    bool fl = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) fl =true;
    }
    if (fl) cout << "YES\n"; else cout << "NO\n";


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