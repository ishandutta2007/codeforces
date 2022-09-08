/**
 *  created: 27/01/2022, 17:43:13
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111;
const long long inf = 1000111222000111222LL;

int t, n, m, a[max_n];

int read() {
    int res = 0, x;
    while (m--) {
        cin >> x;
        res = __gcd(res, x);
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int d = read();
        vector<long long> ans(2);
        for (int i = 0; i < d; ++i) {
            vector<long long> dp{-a[i], a[i]};
            for (int j = i + d; j < n; j += d) {
                vector<long long> ndp{-inf, -inf};
                for (int f1 = 0; f1 < 2; ++f1) {
                    for (int f2 = 0; f2 < 2; ++f2) {
                        int z = (f1 ^ f2 ^ 1) * 2 - 1;
                        ndp[f2] = max(ndp[f2], dp[f1] + z * a[j]);
                    }
                }
                dp.swap(ndp);
            }
            ans[0] += dp[0];
            ans[1] += dp[1];
        }
        cout << max(ans[0], ans[1]) << "\n";
    }
    return 0;
}