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
        int64_t K;
        cin >> N >> K;
        vector<int64_t> a(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        vector<int64_t> p(N + 1);
        for (int i = 1; i <= N; i++) {
            p[i] = p[i - 1] + a[i];
        }
        if (K <= N) {
            int64_t bonus = K * (K - 1) / 2;
            int64_t ans = 0;
            for (int i = 0; i + K <= N; i++) {
                int64_t x = p[i + K] - p[i] + bonus;
                ans = max(ans, x);
            }
            cout << ans << '\n';
            continue;
        }
        // you can get everything except choose(N 2)
        int64_t ans = p[N] + N * (K - 1) - 1LL * N * (N - 1) / 2;
        cout << ans << '\n';
    }
    return 0;
}