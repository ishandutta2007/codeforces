#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int ans = 0, ret = 0;
        for (int step = (1LL << 40); step; step /= 2) {
            if (ans + step >= n) continue;
            ans += step;
            int rem = n - ans;
            rem = rem * (rem - 1) / 2;

            if (rem < ans) {
                ret = max(ret, ans + rem);
                ans -= step;
            }
        }
        cout << max(ret, 2 * ans) << endl;
    }
    return 0;
}