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
        int N;
        cin >> N;
        vector<int> c(N);
        for (int i = 0; i < N; i++) {
            cin >> c[i], c[i]--;
        }
        vector<vector<int>> pos(N);
        for (int i = 0; i < N; i++) {
            pos[c[i]].push_back(i);
        }
        vector<int> ans(N);
        for (int x = 0; x < N; x++) {
            int S = pos[x].size();
            // [b]: last block was placed on cell with x+y having this parity
            array<int, 2> dp = {0, 0};
            for (int i = 0; i < S; i++) {
                int p = pos[x][i] % 2;
                array<int, 2> nxt = {};
                nxt[p] = max(dp[p], dp[1 - p] + 1);
                nxt[1 - p] = dp[1 - p];
                dp = nxt;
            }
            ans[x] = max(dp[0], dp[1]);
        }
        for (int i = 0; i < N; i++) {
            cout << ans[i] << " \n"[i + 1 == N];
        }
    }
    return 0;
}