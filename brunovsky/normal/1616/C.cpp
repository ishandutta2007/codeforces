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

        int ans = N <= 2 ? 0 : N;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int cost = 0;
                for (int k = 0; k < N && cost < ans; k++) {
                    if (k != i && k != j) {
                        cost += (j - i) * A[k] != (j - k) * A[i] + (k - i) * A[j];
                    }
                }
                ans = min(ans, cost);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}