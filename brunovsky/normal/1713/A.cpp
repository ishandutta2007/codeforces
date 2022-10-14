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
        int N, A = 0, B = 0, C = 0, D = 0;
        cin >> N;
        while (N--) {
            int x, y;
            cin >> x >> y;
            if (x > 0) {
                A = max(A, x);
            } else if (x < 0) {
                B = max(B, -x);
            } else if (y > 0) {
                C = max(C, y);
            } else if (y < 0) {
                D = max(D, -y);
            }
        }

        cout << 2 * (A + B + C + D) << '\n';
    }
    return 0;
}