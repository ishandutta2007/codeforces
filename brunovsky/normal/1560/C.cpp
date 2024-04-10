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
        int k;
        cin >> k;
        int n = 1;
        while (k > n * n) {
            n++;
        }
        int r = 0, c = n;
        int m = (n - 1) * (n - 1);
        while (k > m && r < n) {
            m++, r++;
        }
        while (k > m) {
            m++, c--;
        }
        cout << r << ' ' << c << '\n';
    }
    return 0;
}