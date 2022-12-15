#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
using namespace std;
int k[105],h[105];
long long dp[105][105];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &k[i]);
        for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                dp[i][j] = LLONG_MAX / 2;
        dp[1][1] = 1LL * h[1] * (h[1] + 1) / 2;
        dp[0][0] = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i - 1; j++) {
                if (h[j] + k[i] - k[j] < h[i] || dp[i - 1][j] == LLONG_MAX / 2) continue;
                dp[i][j] = dp[j][j] + 1LL * (h[j] + 1 + h[j] + k[i] - k[j]) * (k[i] - k[j]) / 2;
            }
            int f = 1, lst = 0;
            for (int j = 1; j <= i - 1; j++) if (k[j] >= k[i] - h[i] + 1 && h[j] > h[i] - k[i] + k[j]) f = 0;
            if (!f) continue;
            for (int j = 1; j <= i - 1; j++) if (k[j] < k[i] - h[i] + 1) lst = j;
            long long mn = lst==0?0:LLONG_MAX / 2;
            for (int j = 1; j <= lst; j++) mn = min(mn, dp[lst][j]);
            dp[i][i] = mn + 1LL * h[i] * (h[i] + 1) / 2;

            //for(int j=1;j<=i;j++) cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;
        }
        long long ans = LLONG_MAX / 2;
        for (int i = 1; i <= n; i++) ans = min(ans, dp[n][i]);
        printf("%lld\n", ans);
    }
    return 0;
}