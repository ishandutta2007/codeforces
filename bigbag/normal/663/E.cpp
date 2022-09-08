#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 20, max_m = 111111, inf = 1111111111;

int n, m;
int dp[max_n + 1][1 << max_n];
int sum[max_n + 1][1 << max_n];
char a[max_n][max_m];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
        for (int j = 0; j < m; ++j) {
            a[i][j] -= '0';
        }
    }
    for (int i = 0; i < m; ++i) {
        int mask = 0;
        for (int j = 0; j < n; ++j) {
            mask += a[j][i] * (1 << j);
        }
        ++dp[0][mask];
        ++sum[0][mask];
    }
    for (int k = 1; k <= n; ++k) {
        for (int mask = 0; mask < (1 << n); ++mask) {
            for (int i = 0; i < n; ++i) {
                int to = mask ^ (1 << i), z = 1;
                dp[k][mask] += sum[k - 1][to];
                if (k >= 2) {
                    dp[k][mask] -= sum[k - 2][mask];
                }
            }
            dp[k][mask] /= k;
            sum[k][mask] = dp[k][mask];
            if (k >= 2) {
                sum[k][mask] += sum[k - 2][mask];
            }
        }
    }
    int ans = inf;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int res = 0;
        for (int k = 0; k <= n; ++k) {
            res += dp[k][mask] * min(k, n - k);
        }
        ans = min(ans, res);
    }
    printf("%d\n", ans);
    return 0;
}