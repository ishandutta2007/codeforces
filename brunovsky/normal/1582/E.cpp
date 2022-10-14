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
        vector<int> a(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }

        // sqrt(N) possible values of k
        vector<int64_t> sum(N + 1);
        for (int i = 1; i <= N; i++)
            sum[i] = sum[i - 1] + a[i];

        // We do dp backwards
        // For each position, consider a sequence starting there, and the first segment
        // sum equal to k. We want to keep the sums as *large* as possible.

        vector<int> dp = a;
        for (int i = N - 1; i >= 1; i--) {
            dp[i] = max(dp[i], dp[i + 1]);
        }

        int first = N;
        int k = 2;
        while (true) {
            first -= k;
            vector<int> nxt(N + 1, 0);

            for (int i = first; i >= 1; i--) {
                nxt[i] = nxt[i + 1];
                int64_t range = sum[i + k - 1] - sum[i - 1];
                if (range < dp[i + k]) {
                    nxt[i] = max<int64_t>(nxt[i], range);
                    // I'm the dumbest person in the universe
                }
            }

            if (nxt[1] == 0) {
                cout << k - 1 << '\n';
                break;
            } else {
                dp = move(nxt), k++;
            }
        }
    }
    return 0;
}