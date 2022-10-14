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
        int64_t N, S;
        cin >> N >> S;
        // binary search
        int64_t A, B;
        A = (N - 1) / 2;
        B = N - A;
        debug(N, A, B);
        int64_t L = -1, R = S + 1;
        while (L + 1 < R) {
            int64_t M = (L + R) / 2;
            // have N/2 copies of 1, and (N+1)/2 copies of M
            int64_t X = B * M;
            if (X <= S) {
                L = M;
            } else {
                R = M;
            }
        }
        cout << max(L, int64_t(0)) << '\n';
    }
    return 0;
}