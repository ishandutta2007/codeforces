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
        array<int, 3> abc;
        int M;
        cin >> abc[0] >> abc[1] >> abc[2] >> M;
        sort(rbegin(abc), rend(abc));
        auto [a, b, c] = abc;
        if (M > a + b + c - 3) {
            cout << "NO\n";
            continue;
        }
        int d = b - c;
        a -= d, b -= d;
        int e = min(a - b, b);
        a -= 2 * e, b -= e, c -= e;
        assert(a >= 0 && b >= 0 && c >= 0);
        if (b > 0 || c > 0 || a <= M + 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}