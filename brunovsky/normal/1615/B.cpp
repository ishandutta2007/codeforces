#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    constexpr int MAX = 200'000;
    constexpr int B = 20;

    vector<array<int, B>> zeros(MAX + 1);
    for (int i = 1; i <= MAX; i++) {
        zeros[i] = zeros[i - 1];
        for (int b = 0; b < B; b++) {
            zeros[i][b] += ((i >> b) & 1) == 0;
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int l, r;
        cin >> l >> r, l--;
        int ans = INT_MAX;
        for (int b = 0; b < B; b++) {
            ans = min(ans, zeros[r][b] - zeros[l][b]);
        }
        cout << ans << '\n';
    }
    return 0;
}