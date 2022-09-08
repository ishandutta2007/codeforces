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

const int max_n = 5055, inf = 1111111111;

int n, s, e;
long long x[max_n], a[max_n], b[max_n], c[max_n], d[max_n];
char f[max_n][max_n];
long long dp[max_n][max_n];

void read() {
    for (int i = 1; i <= n; ++i) {
        scanf("%I64d", &x[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%I64d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%I64d", &b[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%I64d", &c[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%I64d", &d[i]);
    }
}

void update(int i, int j, long long x) {
    if (f[i][j] == 0) {
        f[i][j] = 1;
        dp[i][j] = x;
    } else {
        dp[i][j] = min(dp[i][j], x);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &s, &e);
    read();
    dp[0][0] = 0;
    f[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        int w = 0;
        if (s <= i) {
            ++w;
        }
        if (e <= i) {
            --w;
        }
        if (w == 0 && i != 0 && i + 1 != n) {
            f[i][0] = 0;
        }
        for (int j = 0; j <= n; ++j) {
            if (f[i][j] == 0) {
                continue;
            }
            //cout << i << " " << j << " : " << dp[i][j] << endl;
            int q = j;
            int w = j;
            if (s <= i) {
                ++w;
            }
            if (e <= i) {
                --w;
            }
            if (q < 0 || w < 0) {
                continue;
            }
            if (s == i + 1) {
                if (q) {
                    update(i + 1, j - 1, dp[i][j] + x[i + 1] + c[i + 1]);
                }
                if (i + 1 < n) {
                    update(i + 1, j, dp[i][j] + d[i + 1] - x[i + 1]);
                }
            } else if (e == i + 1) {
                if (w) {
                    update(i + 1, j, dp[i][j] + x[i + 1] + a[i + 1]);
                }
                if (i + 1 < n) {
                    update(i + 1, j + 1, dp[i][j] - x[i + 1] + b[i + 1]);
                }
            } else {
                if (i + 2 < n) {
                    update(i + 1, j + 1, dp[i][j] - x[i + 1] - x[i + 1] + b[i + 1] + d[i + 1]);
                }
                if (q > 0 && i + 1 < n) {
                    update(i + 1, j, dp[i][j] + b[i + 1] + c[i + 1]);
                }
                if (q > 0 && w > 0) {
                    update(i + 1, j - 1, dp[i][j] + x[i + 1] + x[i + 1] + a[i + 1] + c[i + 1]);
                }
                if (w > 0 && i + 1 < n) {
                    update(i + 1, j, dp[i][j] + a[i + 1] + d[i + 1]);
                }
            }
        }
    }
    printf("%I64d\n", dp[n][0]);
    return 0;
}