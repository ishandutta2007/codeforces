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
        int n, k, r, c;
        cin >> n >> k >> r >> c, r--, c--;
        vector<string> grid(n, string(n, '.'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i + j) % k == (r + c) % k) {
                    grid[i][j] = 'X';
                }
            }
            cout << grid[i] << '\n';
        }
    }
    return 0;
}