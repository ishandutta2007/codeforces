#include <bits/stdc++.h>

using namespace std;

const int max_n = 4044, inf = 1000111222;

int t, n, a[max_n], pr[max_n];
bool dp[2][max_n][max_n];
int sum[2][max_n][max_n];

int get_sum(int tp, int a, int l, int r) {
    l = max(l, 0);
    if (l > r) {
        return 0;
    }
    if (!l) {
        return sum[tp][a][r];
    }
    return sum[tp][a][r] - sum[tp][a][l - 1];
}

void upd(int tp, int a, int b, bool val) {
    dp[tp][a][b] = val;
    sum[tp][a][b] = val;
    if (b) {
        sum[tp][a][b] += sum[tp][a][b - 1];
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < 2 * n; ++i) {
            cin >> a[i];
            --a[i];
        }
        memset(pr, -1, sizeof(pr));
        for (int i = 0; i < 2 * n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (a[j] > a[i]) {
                    pr[i] = j;
                    break;
                }
            }
        }
        upd(0, 0, 0, 1);
        for (int i = 1; i <= 2 * n; ++i) {
            for (int tp = 0; tp < 2; ++tp) {
                for (int a = 0; a <= i; ++a) {
                    const int b = i - a;
                    dp[tp][a][b] = 0;
                    if (a <= n && b <= n) {
                        const int cnt = i - pr[i] - 1;
                        dp[tp][a][b] = get_sum(tp ^ 1, b, a - cnt, a - 1);
                    }
                    upd(tp, a, b, dp[tp][a][b]);
                }
            }
        }
        if (dp[0][n][n] || dp[1][n][n]) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}