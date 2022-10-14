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
        int64_t l, r;
        cin >> l >> r;
        int64_t x = (r + 1) / 2;
        if (x >= l) {
            cout << x - 1 << '\n';
        } else {
            cout << r % l << '\n';
        }
    }
    return 0;
}