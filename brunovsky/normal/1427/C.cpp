#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

void setmax(int& a, int b) { a = max(a, b); }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int R, N;
    cin >> R >> N;
    vector<array<int, 3>> pts(N + 1);
    for (int i = 1; i <= N; i++) {
        auto& [t, x, y] = pts[i];
        cin >> t >> x >> y, x--, y--;
    }
    vector<int> dp(N + 1, INT_MIN);
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        auto [t, x, y] = pts[i];
        for (int j = i - 1; j >= max(0, i - 5 * R); j--) {
            auto [p, a, b] = pts[j];
            if (abs(a - x) + abs(b - y) <= t - p) {
                setmax(dp[i], dp[j] + 1);
            }
        }
    }
    cout << *max_element(begin(dp), end(dp)) << '\n';
    return 0;
}