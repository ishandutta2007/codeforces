#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int64_t lsqrt(int64_t n) {
    int64_t x = sqrt(n);
    x -= x * x > n;
    x += (x + 1) * (x + 1) <= n;
    return x;
}

int64_t count(int64_t n) {
    int64_t x = lsqrt(n);
    return 3 * x - (x * (x + 1) > n) - (x * (x + 2) > n);
}

int64_t query(int64_t l, int64_t r) { return count(r) - count(l - 1); }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int64_t L, R;
        cin >> L >> R;
        cout << query(L, R) << '\n';
    }
    return 0;
}