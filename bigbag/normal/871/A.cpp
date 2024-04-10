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

const int max_n = 1111, inf = 1011111111;

int q, n, dp[max_n], f[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 2; i < max_n; ++i) {
        if (f[i] == 0) {
            for (int j = 2 * i; j < max_n; j += i) {
                f[j] = 1;
            }
        }
    }
    dp[0] = 0;
    for (int i = 1; i < max_n; ++i) {
        dp[i] = -inf;
        for (int j = 1; j <= i; ++j) {
            if (f[j]) {
                dp[i] = max(dp[i], dp[i - j] + 1);
            }
        }
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        if (n < max_n) {
            if (dp[n] < 0) {
                printf("-1\n");
            } else {
                printf("%d\n", dp[n]);
            }
        } else {
            int k = (n - max_n) / 4 + 2;
            n -= 4 * k;
            printf("%d\n", k + dp[n]);
        }
    }
    return 0;
}