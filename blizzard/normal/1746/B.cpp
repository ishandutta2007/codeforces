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
    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i != 0) s[i] = s[i - 1] + a[i]; else s[i] = a[i];
    }
    int sum = s[n - 1];

    int r = n;
    int zeroes = n - sum;
    int ans = min(zeroes, sum);
    for (int i = 0; i < n; i++) {
        int left =  (i > 0 ? s[i - 1] : 0);
        int right = zeroes;
        ans = min(ans, max(right, left));
//        err << r - sum + s[i] << endl;
        //ans = min(ans, )
        sum -= a[i];
        if (a[i] == 0) zeroes--;
//        r--;
    }
    cout << ans << "\n";

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