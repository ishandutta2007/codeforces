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

const int max_n = 100111, inf = 1011111111;

int n, p[5], a[max_n];
long long dp[5][max_n], mx[5][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &n, &p[1], &p[2], &p[3]);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = 1LL * p[i] * a[j] + mx[i - 1][j];
            mx[i][j] = dp[i][j];
            if (j) {
                mx[i][j] = max(mx[i][j], mx[i][j - 1]);
            }
        }
    }
    printf("%I64d\n", mx[3][n - 1]);
    return 0;
}