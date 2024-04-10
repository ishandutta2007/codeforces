#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

auto choose3(int64_t n) { return n * (n - 1) * (n - 2) / 6; }
auto choose2(int64_t n) { return n * (n - 1) / 2; }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    array<array<int, 2>, 2> pts = {};
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        x /= 2, y /= 2;
        pts[abs(x) % 2][abs(y) % 2]++;
    }
    int64_t ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ans += choose3(pts[i][j]);
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int m = 0; m < 2; m++) {
                    ans += choose2(pts[i][j]) * pts[k][m];
                }
            }
            ans -= choose2(pts[i][j]) * pts[i][j];
        }
    }
    cout << ans << '\n';
    return 0;
}