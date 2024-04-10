#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> h(N);
        for (int i = 0; i < N; i++) {
            cin >> h[i];
        }
        if (N % 2 == 1) {
            int64_t ans = 0;
            for (int i = 1; i < N; i += 2) {
                ans += max({0, h[i - 1] - h[i] + 1, h[i + 1] - h[i] + 1});
            }
            cout << ans << '\n';
        } else {
            vector<int64_t> need(N), pref(N), suff(N);
            for (int i = 1; i + 1 < N; i++) {
                need[i] = max({0, h[i - 1] - h[i] + 1, h[i + 1] - h[i] + 1});
            }
            if (N == 4) {
                cout << min(need[1], need[2]) << '\n';
                continue;
            }
            debug(need);
            for (int i = 1; i <= N; i += 2) {
                pref[i] = need[i] + (i > 1 ? pref[i - 2] : 0);
            }
            for (int i = N - 2; i >= 0; i -= 2) {
                suff[i] = need[i] + (i < N - 2 ? suff[i + 2] : 0);
            }
            debug(pref);
            debug(suff);
            int64_t ans = INT64_MAX;
            for (int l = 0, r = (N - 2) / 2; r >= 0; l++, r--) {
                int64_t left = l ? pref[2 * l - 1] : 0;
                int64_t right = r ? suff[N - 2 * r] : 0;
                debug(l, r, left, right);
                ans = min(ans, left + right);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}

// n odd -> 1,3,5,...,n-2
// n even -> (n-2)/2 buildings maximize prefix and suffix separately