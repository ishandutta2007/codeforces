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

int n, a[max_n];
char q[max_n];
string s[max_n];
long long dp[max_n][2];

void update(int a, int b, long long c) {
    if (dp[a][b] == -1) {
        dp[a][b] = c;
    } else {
        dp[a][b] = min(dp[a][b], c);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%s", q);
        s[i] = q;
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    dp[0][1] = a[0];
    for (int i = 0; i + 1 < n; ++i) {
        for (int f = 0; f < 2; ++f) {
            if (dp[i][f] == -1) {
                reverse(s[i].begin(), s[i].end());
                continue;
            }
            for (int ff = 0; ff < 2; ++ff) {
                if (s[i] <= s[i + 1]) {
                    update(i + 1, ff, dp[i][f] + a[i + 1] * ff);
                }
                reverse(s[i + 1].begin(), s[i + 1].end());
            }
            reverse(s[i].begin(), s[i].end());
        }
    }
    long long ans = -1;
    for (int i = 0; i < 2; ++i) {
        if (dp[n - 1][i] == -1) {
            continue;
        }
        if (ans == -1) {
            ans = dp[n - 1][i];
        } else {
            ans = min(ans, dp[n - 1][i]);
        }
    }
    printf("%I64d\n", ans);
    return 0;
}