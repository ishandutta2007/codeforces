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
        int64_t N;
        cin >> N;

        if (N % 2 == 1) {
            cout << 2 << '\n';
        } else {
            int K = 0;
            while (N % 2 == 0) {
                K++, N /= 2;
            }
            if (N == 1) {
                cout << -1 << '\n';
            } else {
                cout << min(int64_t(2) << K, N) << '\n';
            }
        }
    }
    return 0;
}

// 2n divisible by k
// if n is odd, 2 works
// if n is even, clean it up, pick odd divisor?