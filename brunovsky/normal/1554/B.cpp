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
        int N, K;
        cin >> N >> K;
        vector<int> a(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        long best = LLONG_MIN / 2;
        for (int i = 1; i < N; i++) {
            long c = 1LL * N * (N - 1 - 5 * K) / i;
            for (int j = clamp<long>(c, i + 1, N); j <= N; j++) {
                best = max<long>(best, 1LL * i * j - 1LL * K * (a[i] | a[j]));
            }
        }
        cout << best << '\n';
    }
    return 0;
}