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
        int64_t x, y;
        cin >> x >> y;
        int64_t n = 0;
        if (x > y) {
            n = x + y;
        } else if (x == y) {
            n = x;
        } else {
            int64_t a = y / x, r = y % x;
            int64_t k = (y - a * x) / 2;
            if (r == 0) {
                n = x;
            } else {
                n = a * x + k;
            }
        }
        cout << n << '\n';
    }
    return 0;
}