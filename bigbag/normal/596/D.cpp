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

const int max_n = 2002, inf = 1111111111;

int n, h, a[max_n], nxt[max_n], prr[max_n];
double p, dp[max_n][max_n][2][2];
double ff[max_n][max_n][2][2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> h >> p;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    nxt[n - 1] = n - 1;
    for (int i = n - 2; i >= 0; --i) {
        nxt[i] = i;
        if (a[i] + h > a[i + 1]) {
            nxt[i] = nxt[i + 1];
        }
    }
    prr[0] = 0;
    for (int i = 1; i < n; ++i) {
        prr[i] = i;
        if (a[i] - h < a[i - 1]) {
            prr[i] = prr[i - 1];
        }
    }
    double ans = 0;
    for (int f1 = 0; f1 < 2; ++f1) {
        for (int f2 = 0; f2 < 2; ++f2) {
            ff[0][n - 1][f1][f2] = 1;
        }
    }
    for (int len = n; len > 0; --len) {
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1;
            for (int f1 = 0; f1 < 2; ++f1) {
                for (int f2 = 0; f2 < 2; ++f2) {
                    if (l == r) {
                        if (f1 != f2) {
                            continue;
                        }
                        if (f1 == 0) {
                            ans += p * (dp[l][r][f1][f2] + h * ff[l][r][f1][f2]);
                        } else {
                            ans += (1 - p) * (dp[l][r][f1][f2] + h * ff[l][r][f1][f2]);
                        }
                        continue;
                    }
                    if (f1 == 0) {//left tree
                        for (int f = 0; f < 2; ++f) {
                            int q = h;
                            if (f == 0) {
                                q -= max(0, h - (a[l + 1] - a[l]));
                            }
                            dp[l + 1][r][f][f2] += 0.5 * p * (dp[l][r][f1][f2] + q * ff[l][r][f1][f2]);
                            ff[l + 1][r][f][f2] += 0.5 * p * (ff[l][r][f1][f2]);
                        }
                    } else {
                        int nx = nxt[l];
                        if (nx >= r) {
                            if (f1 == f2) {
                                ans += 0.5 * (1 - p) * (dp[l][r][f1][f2] + (a[r] + h - a[l]) * ff[l][r][f1][f2]);
                            }
                        } else {
                            for (int f = 0; f < 2; ++f) {
                                int q = a[nx] + h - a[l];
                                if (f == 0) {
                                    q -= max(0, h - (a[nx + 1] - a[nx] - h));
                                }
                                dp[nx + 1][r][f][f2] += 0.5 * (1 - p) * (dp[l][r][f1][f2] + q * ff[l][r][f1][f2]);
                                ff[nx + 1][r][f][f2] += 0.5 * (1 - p) * (ff[l][r][f1][f2]);
                            }
                        }
                    }

                    if (f2 == 1) {//right tree
                        for (int f = 0; f < 2; ++f) {
                            int q = h;
                            if (f == 1) {
                                q -= max(0, h - (a[r] - a[r - 1]));
                            }
                            dp[l][r - 1][f1][f] += 0.5 * (1 - p) * (dp[l][r][f1][f2] + q * ff[l][r][f1][f2]);
                            ff[l][r - 1][f1][f] += 0.5 * (1 - p) * (ff[l][r][f1][f2]);
                        }
                    } else {
                        int pr = prr[r];
                        if (pr <= l) {
                            if (f1 == f2) {
                                ans += 0.5 * p * (dp[l][r][f1][f2] + (a[r] + h - a[l]) * ff[l][r][f1][f2]);
                            }
                        } else {
                            for (int f = 0; f < 2; ++f) {
                                int q = a[r] - a[pr] + h;
                                if (f == 1) {
                                    q -= max(0, h - (a[pr] - h - a[pr - 1]));
                                }
                                dp[l][pr - 1][f1][f] += 0.5 * p * (dp[l][r][f1][f2] + q * ff[l][r][f1][f2]);
                                ff[l][pr - 1][f1][f] += 0.5 * p * (ff[l][r][f1][f2]);
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%.10f\n", ans);
    return 0;
}