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
        int M;
        cin >> M;
        vector<array<int, 2>> coins(M + 1);
        for (int i = 1; i <= M; i++) {
            cin >> coins[i][0];
        }
        for (int i = 1; i <= M; i++) {
            cin >> coins[i][1];
        }
        vector<array<int, 2>> prefix(M + 1);
        for (int i = 1; i <= M; i++) {
            prefix[i][0] = prefix[i - 1][0] + coins[i][0];
            prefix[i][1] = prefix[i - 1][1] + coins[i][1];
        }
        auto top = [&](int l, int r) {
            return (l > r) ? 0 : prefix[r][0] - prefix[l - 1][0];
        };
        auto bot = [&](int l, int r) {
            return (l > r) ? 0 : prefix[r][1] - prefix[l - 1][1];
        };

        int ans = INT_MAX;
        // suppose Alice drops in the i'th column
        for (int i = 1; i <= M; i++) {
            // Bob gets [i+1,M][0] + [1,i-1][0]
            int best = max(top(i + 1, M), bot(1, i - 1));
            ans = min(ans, best);
        }
        cout << ans << '\n';
    }
    return 0;
}