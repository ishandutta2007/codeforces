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
    int N;
    cin >> N;
    vector<long> c(N + 2);
    for (int i = 1; i <= N; i++) {
        cin >> c[i];
    }

    long ans = 0;
    for (int l = 1; l < N; l += 2) {
        long delta = 0;
        long lower = 0;
        for (int r = l + 1; r <= N; r += 2) {
            long A = c[l] + lower; // how many we can add on the left
            if (A >= 1) {
                long B = c[l] + delta; // if we pick c[r] on the left, pick
                if (B > c[r]) {
                    A -= B - c[r];
                    B = c[r];
                }
                if (A > 0 && B > 0) {
                    long add = min<long>(A, B);
                    debug(l, r, A, B, add);
                    ans += add;
                }
            }
            lower = min(lower, delta - c[r] + 1);
            delta += c[r + 1] - c[r];
        }
    }
    cout << ans << '\n';
    return 0;
}