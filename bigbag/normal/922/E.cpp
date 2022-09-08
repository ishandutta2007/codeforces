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

const int max_n = 10011, inf = 1011111111;

int n, sum, start, add_to_max, restore, a[max_n], cost[max_n];
long long dp[2][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &n, &start, &add_to_max, &restore);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &cost[i]);
    }
    int q1 = 0, q2 = 1;
    memset(dp, -1, sizeof(dp));
    dp[q1][0] = start;
    for (int i = 0; i < n; ++i) {
        memset(dp[q2], -1, sizeof(dp[q2]));
        for (int j = 0; j <= sum; ++j) {
            dp[q1][j] = min(dp[q1][j], start + 1LL * j * add_to_max);
            long long cur = dp[q1][j];
            for (int k = 0; k <= a[i] && cur >= 0; ++k, cur -= cost[i]) {
                dp[q2][j + k] = max(dp[q2][j + k], cur + restore);
            }
        }
        sum += a[i];
        swap(q1, q2);
    }
    for (int i = sum; i >= 0; --i) {
        if (dp[q1][i] >= 0) {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}