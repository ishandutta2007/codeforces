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
        int n, m, rb, cb, rd, cd;
        cin >> n >> m >> rb >> cb >> rd >> cd, rb--, cb--, rd--, cd--;
        int rows = rb <= rd ? rd - rb : (n - rb - 1) + (n - rb - 1) + (rb - rd);
        int cols = cb <= cd ? cd - cb : (m - cb - 1) + (m - cb - 1) + (cb - cd);
        cout << min(rows, cols) << '\n';
    }
    return 0;
}