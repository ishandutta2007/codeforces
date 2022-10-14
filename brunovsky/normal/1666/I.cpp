#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int DIG(int r, int c) {
    cout << "DIG " << r << ' ' << c << endl;
    int ans;
    cin >> ans;
    return ans;
}

int SCAN(int r, int c) {
    cout << "SCAN " << r << ' ' << c << endl;
    int ans;
    cin >> ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int a = SCAN(1, 1) + 4;
        int b = SCAN(n, 1) - 2 * n + 2;
        int rs = (a - b) / 2;
        int cs = (a + b) / 2;
        int c = SCAN(rs / 2, 1) - cs + 2;
        int d = SCAN(1, cs / 2) - rs + 2;
        int r1 = rs / 2 - c / 2;
        int r2 = rs / 2 + (c + 1) / 2;
        int c1 = cs / 2 - d / 2;
        int c2 = cs / 2 + (d + 1) / 2;
        if (DIG(r1, c1)) {
            DIG(r2, c2); // 6
        } else {
            DIG(r1, c2);
            DIG(r2, c1); // 7
        }
    }
    return 0;
}