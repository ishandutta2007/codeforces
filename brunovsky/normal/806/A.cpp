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
        int64_t x, y, p, q;
        cin >> x >> y >> p >> q;
        int64_t g = gcd(p, q);
        p /= g;
        q /= g;
        int64_t py = p * y;
        int64_t qx = q * x;
        int64_t d = q - p;
        if (p == 0) {
            cout << (x == 0 ? 0 : -1) << '\n';
        } else if (p == q) {
            cout << (x == y ? 0 : -1) << '\n';
        } else if (qx == py) {
            cout << "0\n";
        } else if (qx > py) {
            int64_t k = (qx - py + p - 1) / p;
            if (int64_t m = (y + k) % q; m != 0) {
                k += q - m;
            }
            cout << k << '\n';
        } else if (qx < py) {
            int64_t k = (py - qx + d - 1) / d;
            if (int64_t m = (y + k) % q; m != 0) {
                k += q - m;
            }
            cout << k << '\n';
        } else {
            assert(false);
        }
    }
    return 0;
}