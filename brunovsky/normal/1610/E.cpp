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
        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        if (N == 2) {
            cout << 0 << '\n';
            continue;
        }

        vector<int> next(N, N);
        for (int i = N - 2; i >= 0; i--) {
            next[i] = A[i] == A[i + 1] ? next[i + 1] : i + 1;
        }

        int ans = 2;

        for (int s = 0; s + ans < N; s = next[s]) {
            int i = next[s];
            if (i == N) {
                ans = max(ans, i - s);
                break;
            }
            int cnt = i + 1 - s;
            int j = lower_bound(begin(A) + i + 1, end(A), 2 * A[i] - A[s]) - begin(A);
            while (j < N) {
                cnt++, i = j;
                j = lower_bound(begin(A) + i + 1, end(A), 2 * A[i] - A[s]) - begin(A);
            }
            ans = max(ans, cnt);
        }

        cout << N - ans << '\n';
    }
    return 0;
}

// Only need to consider first, last, second-to-last to determine bad
// Increasing a