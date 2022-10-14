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
        int64_t W, H;
        cin >> W >> H;

        array<vector<int>, 4> pts;
        for (int s = 0; s < 4; s++) {
            int N;
            cin >> N;
            pts[s].resize(N);
            for (int i = 0; i < N; i++) {
                cin >> pts[s][i];
            }
            sort(begin(pts[s]), end(pts[s]));
        }

        int64_t ans = 0;
        ans = max(ans, H * (pts[0].back() - pts[0].front()));
        ans = max(ans, H * (pts[1].back() - pts[1].front()));
        ans = max(ans, W * (pts[2].back() - pts[2].front()));
        ans = max(ans, W * (pts[3].back() - pts[3].front()));
        cout << ans << '\n';
    }
    return 0;
}