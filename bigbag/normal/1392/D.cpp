#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int t, n, a[max_n], dp[max_n][2][2];
char s[max_n];

void clr() {
    for (int i = 0; i <= n; ++i) {
        dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = inf;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%s", &n, s);
        for (int i = 0; i < n; ++i) {
            a[i] = (s[i] == 'L');
        }
        int ans = inf;
        for (int f1 = 0; f1 < 2; ++f1) {
            for (int f2 = 0; f2 < 2; ++f2) {
                clr();
                dp[2][f1][f2] = int(f1 != a[0]) + int(f2 != a[1]);
                for (int i = 2; i < n; ++i) {
                    for (int last1 = 0; last1 < 2; ++last1) {
                        for (int last2 = 0; last2 < 2; ++last2) {
                            for (int tp = 0; tp < 2; ++tp) {
                                if (last1 == last2 && last2 == tp) {
                                    continue;
                                }
                                int res = dp[i][last1][last2] + (tp != a[i]);
                                dp[i + 1][last2][tp] = min(dp[i + 1][last2][tp], res);
                            }
                        }
                    }
                }
                for (int last1 = 0; last1 < 2; ++last1) {
                    for (int last2 = 0; last2 < 2; ++last2) {
                        if (f1 == f2 && f2 == last2) {
                            continue;
                        }
                        if (f1 == last1 && last1 == last2) {
                            continue;
                        }
                        if (n == 3 && last1 != f2) {
                            continue;
                        }
                        //cout << f1 << " " << f2 << " " << last1 << " " << last2 << ": " << dp[n][last1][last2] << endl;
                        ans = min(ans, dp[n][last1][last2]);
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}