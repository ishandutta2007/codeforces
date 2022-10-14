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
        long c, d;
        cin >> c >> d;
        if (c == 0 && d == 0) {
            cout << 0 << '\n';
        } else if (c == d || c == -d) {
            cout << 1 << '\n';
        } else if (c % 2 == d % 2) {
            cout << 2 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}