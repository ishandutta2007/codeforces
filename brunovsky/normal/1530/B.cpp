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
        int H, W;
        cin >> H >> W;
        vector<string> ans(H, string(W, '0'));
        H--, W--;
        ans[0][0] = ans[0][W] = ans[H][0] = ans[H][W] = '1';
        for (int i = 2; i + 2 <= W; i += 2) {
            ans[0][i] = ans[H][i] = '1';
        }
        for (int i = 2; i + 2 <= H; i += 2) {
            ans[i][0] = ans[i][W] = '1';
        }
        for (int i = 0; i <= H; i++) {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}