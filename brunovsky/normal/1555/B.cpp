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
        int W, H;
        cin >> W >> H;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int wa = x2 - x1;
        int ha = y2 - y1;
        int wb, hb;
        cin >> wb >> hb;
        if (wa + wb > W && ha + hb > H) {
            cout << -1 << '\n';
        } else {
            int ans = max(H, W);
            // check left, right, then move left, move right
            if (wb <= x1 || wb <= W - x2) {
                ans = 0;
            } else if (wa + wb <= W) {
                // try to slide the table right
                int right = wb - x1;
                int left = wb - (W - x2);
                ans = min({ans, left, right});
            }
            if (hb <= y1 || hb <= H - y2) {
                ans = 0;
            } else if (ha + hb <= H) {
                int up = hb - y1;
                int down = hb - (H - y2);
                ans = min({ans, up, down});
            }
            cout << ans << '\n';
        }
    }
    return 0;
}