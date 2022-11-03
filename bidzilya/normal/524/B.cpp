#include <bits/stdc++.h>
using namespace std;

const int kMaxH = 1e3;
const int kInf = 1e9;

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<int> > dp(kMaxH + 1, vector<int>(n, kInf));
    vector<int> w(n), h(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &w[i], &h[i]);
    }
    dp[w[0]][0] = min(dp[w[0]][0], h[0]);
    dp[h[0]][0] = min(dp[h[0]][0], w[0]);
    for (int i = 1; i < n; ++i) {
        for (int lh = 0; lh <= kMaxH; ++lh) {
            int nh = max(lh, w[i]);
            dp[nh][i] = min(dp[nh][i], dp[lh][i - 1] + h[i]);
            nh = max(lh, h[i]);
            dp[nh][i] = min(dp[nh][i], dp[lh][i - 1] + w[i]);
        }
    }

    int ans = kInf;
    for (int lh = 0; lh <= kMaxH; ++lh) {
        if (dp[lh][n - 1] < kInf) {
            ans = min(ans, lh * dp[lh][n - 1]);
        }
    }

    printf("%d\n", ans);

    return 0;
}