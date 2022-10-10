#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#define log clog << __LINE__ << ": "
#define _ << ' ' <<
#endif

#define long long long
#define ii pair<int, int>
#define ve vector
#define sz(v) ((int) v.size())
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define xx first
#define yy second
#define pb push_back

int n, m, k;
ve<int> a;
ve<ve<int>> cost;
ve<ve<ve<long>>> dp;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    scanf("%d%d%d", &n, &m, &k);
    a.resize(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    cost.resize(n, ve<int>(m + 1));
    for (int i = 0; i < n; ++i) {
        for (int f = 1; f <= m; ++f) {
            scanf("%d", &cost[i][f]);
        }
    }

    dp.resize(n, ve<ve<long>>(n + 2, ve<long>(m + 1, LLONG_MAX)));
    if (a[0]) dp[0][1][a[0]] = 0;
    else {
        for (int i = 1; i <= m; ++i) {
            dp[0][1][i] = cost[0][i];
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int g = 0; g <= n; ++g) {
            for (int l = 1; l <= m; ++l) {
                if (a[i]) {
                    int ng = g + (a[i] != l);
                    dp[i][ng][a[i]] = min(dp[i][ng][a[i]], dp[i - 1][g][l]);
                    continue;
                }
                for (int nl = 1; nl <= m; ++nl) {
                    if (dp[i - 1][g][l] == LLONG_MAX) continue;
                    int ng = g;
                    if (nl != l) ++ng;
                    dp[i][ng][nl] = min(dp[i][ng][nl], dp[i - 1][g][l] + (long)cost[i][nl]);
                }
            }
        }
    }

    long ans = LLONG_MAX;
    if (a[n - 1]) ans = dp[n - 1][k][a[n - 1]];
    else {
        for (int i = 1; i <= m; ++i) {
            ans = min(ans, dp[n - 1][k][i]);
        }
    }

    if (ans >= LLONG_MAX) {
        cout << -1;
    } else cout << ans;

    return 0;
}