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

const int max_n = 20, inf = 1111111111;

int n;
char f[1 << max_n][max_n];
double a[max_n][max_n], dp[1 << max_n][max_n];

bool get_bit(int x, int poz) {
    return (bool) (x & (1 << poz));
}

void get_dp(int mask, int poz) {
    if (f[mask][poz]) {
        return;
    }
    f[mask][poz] = 1;
    if (mask == (1 << n) - 1) {
        dp[mask][poz] = 0;
        if (poz == 0) {
            dp[mask][poz] = 1;
        }
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (get_bit(mask, i) == 0) {
            get_dp(mask | (1 << i), poz);
            get_dp(mask | (1 << i), i);
            dp[mask][poz] = max(dp[mask | (1 << i)][i] * a[i][poz] + dp[mask | (1 << i)][poz] * a[poz][i], dp[mask][poz]);
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%lf", &a[i][j]);
        }
    }
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        get_dp(1 << i, i);
        ans = max(ans, dp[1 << i][i]);
    }
    printf("%.10f\n", ans);
    return 0;
}