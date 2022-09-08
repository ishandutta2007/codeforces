#include <bits/stdc++.h>

using namespace std;

const int max_n = 3555, inf = 1000111222;

int t, n, m, k, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        --m;
        k = min(k, m);
        int ans = 0;
        for (int l = 0; l <= k; ++l) {
            const int r = n - 1 - (k - l);
            const int cnt = m - k;
            int p1 = l, p2 = r - cnt;
            int res = inf;
            for (int i = 0; i <= cnt; ++i) {
                res = min(res, max(a[p1], a[p2]));
                ++p1;
                ++p2;
            }
            //cout << l << " " << r << ": " << res << endl;
            ans = max(ans, res);
        }
        cout << ans << "\n";
    }
    return 0;
}