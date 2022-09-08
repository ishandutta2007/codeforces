#include <bits/stdc++.h>

using namespace std;

const int max_n = 103;
const long double inf = 1e18, eps = 1e-9;
const int max_x = 1011;

int tests, n;
pair<int, int> a[max_n];
long double C, T, dp[2][max_n][max_x], pw[max_n];

void clr(int q) {
    for (int i = 0; i < max_n; ++i) {
        fill(dp[q][i], dp[q][i] + max_x, inf);
    }
}

void upd(int a, int b, int c, long double x) {
    if (dp[a][b][c] > x) {
        dp[a][b][c] = x;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    pw[0] = 0.9;
    for (int i = 1; i < max_n; ++i) {
        pw[i] = pw[i - 1] * 0.9;
    }
    cin >> tests;
    dp[0][0][0] = 1.5;
    while (tests--) {
        cin >> n;
        cin >> C >> T;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
        }
        sort(a, a + n);
        reverse(a, a + n);
        int q1 = 0, q2 = 1;
        clr(q1);
        dp[q1][0][0] = 0;
        for (int i = 0; i < n; ++i) {
            clr(q2);
            for (int j = 0; j <= i; ++j) {
                for (int points = 0; points <= 10 * j; ++points) {
                    upd(q2, j, points, dp[q1][j][points]);
                    upd(q2, j + 1, points + a[i].second, dp[q1][j][points] + a[i].first / pw[j]);
                }
            }
            swap(q1, q2);
        }
        int ans = 0;
        for (int i = 0; i < max_x; ++i) {
            for (int j = 0; j <= n; ++j) {
                long double t = max((long double) 0, (T - 10 * j) / 2.0 - 0.5 / C);
                long double cmp = (T - t) * (1 + C * t);
                if (dp[q1][j][i] + (10 * j) * (1 + C * t) + eps < cmp) {
                    ans = i;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}