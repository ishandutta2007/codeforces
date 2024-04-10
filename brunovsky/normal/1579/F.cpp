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
        int N, d;
        cin >> N >> d;
        vector<int16_t> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        int g = gcd(d, N);
        debug(N, d, g);
        int ans = 0;

        for (int x = 0; x < g; x++) {
            vector<int16_t> cycle;
            int i = x;
            do {
                cycle.push_back(a[i]);
                i = (i + N - d) % N;
            } while (i != x);

            int C = cycle.size();
            int ones = 0;
            int max_ones = 0;

            for (int i = 0; i < C; i++) {
                cycle.push_back(cycle[i]);
            }
            for (int i = 0; i < 2 * C; i++) {
                ones = cycle[i] == 1 ? ones + 1 : 0;
                max_ones = max(max_ones, ones);
            }

            if (ones == 2 * C) {
                ans = -1;
                break;
            }
            ans = max(ans, max_ones);
        }

        cout << ans << '\n';
    }
    return 0;
}