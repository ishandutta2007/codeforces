#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 105;
const int MAX_P = 10;
const ld eps = 1e-4;

struct ff {
    int a;
    int p;
};

int n;
ld c, t;
pair<int, int> arr[MAX_N];
ld dp[MAX_N][MAX_N][MAX_N * MAX_P];
ld pw[MAX_N];

ld read_d() {
    double x;
    scanf("%lf", &x);
    return x;
}

int hui() {
    scanf("%d", &n);
    c = read_d();
    t = read_d();

    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &arr[i].first, &arr[i].second);
    }
    sort(arr, arr + n);
    reverse(arr, arr + n);

    dp[0][0][0] = 0.0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            for (int sc = 0; sc <= n * MAX_P; ++sc) {
                dp[i][j][sc] = dp[i - 1][j][sc];
                if (j && sc - arr[i - 1].second >= 0) {
                    dp[i][j][sc] = min(dp[i][j][sc], dp[i - 1][j - 1][sc - arr[i - 1].second] + arr[i - 1].first / pw[j]);
                }
            }
        }
    }

    int ans = 0;
    for (int pr = 0; pr <= n; ++pr) {
        for (int sc = 0; sc <= n * MAX_P; ++sc) {
            ld tt = max(0.0l, (sqrtl(dp[n][pr][sc] * c) - 1) / c);
            if (dp[n][pr][sc] / (1 + tt * c) + 10.0l * pr + tt <= t + eps) {
                ans = max(ans, sc);
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}

int main() {
#ifdef CH_EGOR
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
#endif

    pw[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        pw[i] = pw[i - 1] * 0.9;
    }

    for (int i = 0; i < MAX_N; ++i) {
        for (int j = 0; j < MAX_N; ++j) {
            for (int sc = 0; sc < MAX_N * MAX_P; ++sc) {
                dp[i][j][sc] = LLINF;
            }
        }
    }

    int t;
    scanf("%d", &t);
    while (t--) {
        hui();
    }

    return 0;
}