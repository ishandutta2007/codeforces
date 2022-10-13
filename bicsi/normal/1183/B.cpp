#include <bits/stdc++.h>

using namespace std;

int main() {
    int q; cin >> q;
    while (q--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        int ans = -1;
        for (int i = 0; i < n; ++i) {
            int cand = a[i] + k;
            bool bad = false;
            for (int j = 0; j < n; ++j) {
                if (abs(cand - a[j]) > k) {
                    bad = true;
                    break;
                }
            }
            if (!bad) ans = max(ans, cand);
        }
        cout << ans << '\n';
    }
    return 0;
}