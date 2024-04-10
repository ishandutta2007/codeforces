#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    int q; cin >> q;
    while (q--) {
        int k, n, a, b; cin >> k >> n >> a >> b;
        int lo = 0, hi = n;
        int sol = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int need = a * mid + b * (n - mid);
            if (need < k) {
                sol = mid;
                lo = mid + 1;
            } else hi = mid - 1;
        }
        cout << sol << '\n';
    }
    return 0;
}