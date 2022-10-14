#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    bool win[101][101][2] = {};
    win[0][0][0] = true;
    win[1][0][0] = true;
    win[0][1][1] = true;
    for (int even = 0; even <= 100; even++) {
        for (int odd = max(0, 2 - even); odd <= 100; odd++) {
            for (int w : {0, 1}) {
                if (even > 0) {
                    win[even][odd][w] |= (even == 1 || win[even - 2][odd][w]) &&
                                         (odd == 0 || win[even - 1][odd - 1][w]);
                }
                if (odd > 0) {
                    win[even][odd][w] |= (odd == 1 || win[even][odd - 2][!w]) &&
                                         (even == 0 || win[even - 1][odd - 1][!w]);
                }
            }
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int even = 0, odd = 0;
        for (int i = 0; i < N; i++) {
            int x;
            cin >> x;
            even += x % 2 == 0;
            odd += x % 2 != 0;
        }
        cout << (win[even][odd][0] ? "Alice" : "Bob") << '\n';
    }
    return 0;
}