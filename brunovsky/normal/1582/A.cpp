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
        int64_t a, b, c;
        cin >> a >> b >> c;
        int64_t s = a + 2 * b + 3 * c;
        int64_t x = s / 2, y = s - x;
        // a>=1,b>=1,c>=1
        cout << y - x << '\n';
    }

    return 0;
}