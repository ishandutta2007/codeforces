#include <bits/stdc++.h>
using namespace std;

const int N = 770;

long double f[N][N+1], e[N][N+1], d[N][N+1], _e[N];

int main() {
    int n, m; cin >> n >> m;
    long double p = m * 1e-9;
    long double q = 1 - p;
    for (int i = 1; i <= n && i < N; i++) {
        for (int j = 1; j <= i + 1 && j < N + 1; j++) {
            if (j == 1) {
                f[i][j] = p;
                d[i][j] = i == 1 ? p : p * q;
                e[i][j] = i == 1 ? p : p * (_e[i - 1] + q);
            } else if (j == 2) {
                f[i][j] = i == 1 ? q : q + p * p;
                d[i][j] = i == 1 ? 1 : d[i][j - 1] + f[i][j] * d[i - 1][j - 1];
                e[i][j] = i == 1 ? p + 2 * q : e[i][1] + (2 * d[i - 1][j - 1] + e[i - 1][j - 1]) * f[i][j];
            } else {
                f[i][j] = f[i][j - 1] * f[i - 1][j - 1];
                d[i][j] = d[i][j - 1] + f[i][j] * d[i - 1][j - 1];
                e[i][j] = e[i][j - 1] + (j * d[i - 1][j - 1] + e[i - 1][j - 1]) * f[i][j];
            }
        }
        _e[i] = i == 1 ? 2 * q : (e[i][i + 1] - e[i][1]) / (q + p * p) * q;
    }
    long double ans = 0;
    if (n < N) ans = e[n][n + 1];
    else ans = (e[N - 1][N] - e[N - 2][N - 1]) * (n - N + 1) + e[N - 1][N];
    cout << setprecision(10) << ans << endl;
    return 0;
}