#include <iostream>
#include <deque>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <map>
#include <cassert>
#include <unordered_map>
using namespace std;

const int kInf = 1e9 + 1;

int main()
{
    int n, T;
    scanf("%d%d", &n, &T);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    const int kMaxA = 300;
    vector<int> amount(kMaxA + 1, 0);
    for (int i = 0; i < n; ++i) {
        ++amount[a[i]];
    }
    vector<vector<int> > dp(n, vector<int>(n, -kInf));
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
        for (int j = i + 1; j < n; ++j) {
            for (int t = i; t < j; ++t) {
                if (dp[i][t] < 0) {
                    continue;
                }
                if (a[t] <= a[j]) {
                    dp[i][j] = max(dp[i][j], dp[i][t] + 1);
                }
            }
        }
    }
    vector<vector<int> > ldp(n + 1, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int l = 0; l < n; ++l) {
                if (a[j] <= a[l]) {
                    for (int t = l; t < n; ++t) {
                        if (dp[l][t] < 0) {
                            continue;
                        }
                        ldp[i + 1][t] = max(ldp[i + 1][t], ldp[i][j] + dp[l][t]);
                    }
                }
            }
        }
    }
    vector<vector<int> > rdp(n + 1, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int r = 0; r < n; ++r) {
                if (a[r] <= a[j]) {
                    for (int t = r; t >= 0; --t) {
                        if (dp[t][r] < 0) {
                            continue;
                        }
                        rdp[i + 1][t] = max(rdp[i + 1][t], rdp[i][j] + dp[t][r]);
                    }
                }
            }
        }
    }
    int ans = 0;
    vector<int> ldp_opt(n + 1);
    vector<int> rdp_opt(n + 1);
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        ldp_opt.assign(n + 1, 0);
        for (int len = 0; len <= n; ++len) {
            for (int r = 0; r < n; ++r) {
                if (a[r] <= a[i]) {
                    ldp_opt[len] = max(ldp_opt[len], ldp[len][r]);
                }
            }
        }
        rdp_opt.assign(n + 1, 0);
        for (int len = 0; len <= n; ++len) {
            for (int l = 0; l < n; ++l) {
                if (a[i] <= a[l]) {
                    rdp_opt[len] = max(rdp_opt[len], rdp[len][l]);
                }
            }
        }
        for (int l = 0; l <= n; ++l) {
            for (int r = 0; r <= n; ++r) {
                if (l + r <= T) {
                    int t = T - (l + r);

                    ans = max(ans, ldp_opt[l] + rdp_opt[r] + t * amount[a[i]]);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}