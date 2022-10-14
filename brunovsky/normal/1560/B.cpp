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
        int a, b, c;
        cin >> a >> b >> c;
        int N = abs(a - b);
        if (c > 2 * N || a > 2 * N || b > 2 * N) {
            cout << -1 << '\n';
        } else {
            int d = (c + N) % (2 * N);
            if (d == 0) {
                d = 2 * N;
            }
            cout << d << '\n';
        }
    }
    return 0;
}