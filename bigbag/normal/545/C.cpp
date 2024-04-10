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

const int max_n = 111111, inf = 1111111111;

int n, x[max_n], h[max_n], dp[max_n][3];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &h[i]);
    }
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = 1;
    for (int i = 1; i < n; ++i) {
        dp[i][0] = -1;
        if (x[i] - h[i] > x[i - 1]) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        }
        if (x[i] - h[i] > x[i - 1] + h[i - 1]) {
            dp[i][0] = max(dp[i][0], dp[i - 1][2]);
        }
        ++dp[i][0];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        if (x[i] > x[i - 1] + h[i - 1]) {
            dp[i][1] = max(dp[i][1], dp[i - 1][2]);
        }
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]);
        if (x[i] > x[i - 1] + h[i - 1]) {
            dp[i][2] = max(dp[i][2], dp[i - 1][2]);
        }
        ++dp[i][2];
    }
    printf("%d\n", max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])));
    return 0;
}