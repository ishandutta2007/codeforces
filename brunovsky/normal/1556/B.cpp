#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N + 1);
        int zeros = 0, ones = 0;
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
            A[i] %= 2;
            zeros += A[i] == 0;
            ones += A[i] == 1;
        }

        if (abs(zeros - ones) >= 2) {
            cout << -1 << '\n';
            continue;
        }

        vector<int> where[2];
        for (int i = 1; i <= N; i++) {
            where[A[i]].push_back(i);
        }

        long ans = 1e12;
        // try starting with 1
        if (ones >= zeros) {
            long cost = 0;
            for (int i = 0; i < ones; i++) {
                int k = 2 * i + 1;
                cost += abs(k - where[1][i]);
            }
            ans = min(ans, cost);
        }
        // try starting with 0
        if (zeros >= ones) {
            long cost = 0;
            for (int i = 0; i < zeros; i++) {
                int k = 2 * i + 1;
                cost += abs(k - where[0][i]);
            }
            ans = min(ans, cost);
        }

        cout << ans << '\n';
    }
    return 0;
}