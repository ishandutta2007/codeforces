/**
 *  created: 07/06/2022, 17:47:11
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 202222, inf = 1000111222;

int t, n, k, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> c(k);
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ans += a[i] / k;
            ++c[a[i] % k];
        }
        int l = 0, r = k - 1;
        while (l < r) {
            if (l + r < k) {
                ++l;
                continue;
            }
            if (!c[l]) {
                ++l;
                continue;
            }
            if (!c[r]) {
                --r;
                continue;
            }
            int add = min(c[l], c[r]);
            ans += add;
            c[l] -= add;
            c[r] -= add;
        }
        if (l == r && l + r >= k) {
            ans += c[l] / 2;
        }
        cout << ans << "\n";
    }
    return 0;
}