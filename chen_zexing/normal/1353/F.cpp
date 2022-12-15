#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
using namespace std;
long long map[105][105],dp[105][105];
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%lld", &map[i][j]);
        long long ans = LLONG_MAX;
        for (int x = 1; x <= n; x++)
            for (int y = 1; y <= m; y++) {
                memset(dp, 0, sizeof(dp));
                long long o = map[x][y] - x - y + 2;
                if (o > map[1][1]) continue;
                dp[1][1] = map[1][1] - o;
                for (int i = 1; i <= n; i++) dp[i][0] = LLONG_MAX / 2;
                for (int i = 1; i <= m; i++) dp[0][i] = LLONG_MAX / 2;
                for (int i = 1; i <= n; i++)
                    for (int j = 1; j <= m; j++) {
                        if (i == 1 && j == 1) continue;
                        if (o + i + j - 2 > map[i][j]) {
                            dp[i][j] = LLONG_MAX / 2;
                            continue;
                        }
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + map[i][j] - o - i - j + 2;
                    }
                if (dp[n][m] < ans) ans = dp[n][m];
            }
        printf("%lld\n", ans);
    }
    return 0;
}