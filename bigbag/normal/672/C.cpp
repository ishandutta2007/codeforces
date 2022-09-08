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

const int max_n = 111111;
const long long inf = 1111111111111111111LL;

int n, ax[3], ay[3], x[max_n], y[max_n];
long double a[max_n], mn[2][max_n];

long double dist(int x1, int y1, int x2, int y2) {
    x1 -= x2;
    y1 -= y2;
    return sqrt((long double) ((1LL * x1 * x1) + (1LL * y1 * y1)));
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 3; ++i) {
        scanf("%d%d", &ax[i], &ay[i]);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
    }
    long double ans = inf, q = 0;
    for (int j = 0; j < n; ++j) {
        q += 2 * dist(ax[2], ay[2], x[j], y[j]);
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            long double res = dist(ax[i], ay[i], x[j], y[j]) + dist(ax[2], ay[2], x[j], y[j]);
            res += q - 2 * dist(ax[2], ay[2], x[j], y[j]);
            ans = min(ans, res);
        }
    }
    if (n > 1) {
        for (int j = 0; j < n; ++j) {
            a[j] = dist(ax[1], ay[1], x[j], y[j]) - dist(ax[2], ay[2], x[j], y[j]);
        }
        mn[0][0] = a[0];
        for (int j = 1; j < n; ++j) {
            mn[0][j] = min(mn[0][j - 1], a[j]);
        }
        mn[1][n - 1] = a[n - 1];
        for (int j = n - 2; j >= 0; --j) {
            mn[1][j] = min(mn[1][j + 1], a[j]);
        }
        for (int j = 0; j < n; ++j) {
            long double res = dist(ax[0], ay[0], x[j], y[j]) + dist(ax[2], ay[2], x[j], y[j]);
            res += q - 2 * dist(ax[2], ay[2], x[j], y[j]);
            long double f = inf;
            if (j) {
                f = min(f, mn[0][j - 1]);
            }
            if (j + 1 < n) {
                f = min(f, mn[1][j + 1]);
            }
            ans = min(ans, res + f);
        }
    }
    printf("%.10f\n", (double) ans);
    return 0;
}