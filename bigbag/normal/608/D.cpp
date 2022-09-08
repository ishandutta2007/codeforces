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

const int max_n = 505, inf = 1111111111;

int n, a[max_n], dp[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i) {
            if (len == 1) {
                dp[len][i] = 1;
            } else if (len == 2) {
                if (a[i] == a[i + 1]) {
                    dp[len][i] = 1;
                } else {
                    dp[len][i] = 2;
                }
            } else {
                dp[len][i] = inf;
                if (a[i] == a[i + len - 1]) {
                    dp[len][i] = dp[len - 2][i + 1];
                }
                for (int j = i; j < i + len - 1; ++j) {
                    dp[len][i] = min(dp[len][i], dp[j - i + 1][i] + dp[len - (j - i + 1)][j + 1]);
                }
            }
        }
    }
    printf("%d\n", dp[n][0]);
    return 0;
}