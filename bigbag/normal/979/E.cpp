#include <bits/stdc++.h>

using namespace std;

const int max_n = 51, mod = 1000000007;

int dp[2][max_n][max_n][max_n], C[max_n][max_n], pw[max_n];
int n, f, a[max_n], b[2][2];

void init() {
    pw[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pw[i] = (2LL * pw[i - 1]) % mod;
    }
    C[0][0] = 1;
    for (int i = 1; i < max_n; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }
}

int main() {
    init();
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> f;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int q1 = 0, q2 = 1;
    dp[q1][0][0][0] = 1;
    for (int i = n - 1; i >= 0; --i) {
        memset(dp[q2], 0, sizeof(dp[q2]));
        int st = 0, fin = 2;
        if (a[i] == 1) {
            st = 1;
        } else if (a[i] == 0) {
            fin = 1;
        }
        for (int cur = st; cur < fin; ++cur) {
            int need = n - i - 1;
            for (int c00 = 0; c00 <= need; ++c00) {
                for (int c01 = 0; c00 + c01 <= need; ++c01) {
                    for (int c10 = 0; c00 + c01 + c10 <= need; ++c10) {
                        if (dp[c00][c01][c10] == 0) {
                            continue;
                        }
                        int c11 = need - c00 - c01 - c10;
                        b[0][0] = c00;
                        b[0][1] = c01;
                        b[1][0] = c10;
                        b[1][1] = c11;
                        int op = cur ^ 1;
                        for (int j = 0; j <= b[op][1]; ++j) {
                            int res = 1 ^ (j % 2);
                            ++b[cur][res];
                            int x = dp[q1][c00][c01][c10];
                            x = (1LL * x * C[b[op][1]][j]) % mod;
                            x = (1LL * x * pw[need - b[op][1]]) % mod;
                            dp[q2][b[0][0]][b[0][1]][b[1][0]] += x;
                            dp[q2][b[0][0]][b[0][1]][b[1][0]] %= mod;
                            --b[cur][res];
                        }
                    }
                }
            }
        }
        swap(q1, q2);
    }
    int need = n;
    int ans = 0;
    for (int c00 = 0; c00 <= need; ++c00) {
        for (int c01 = 0; c00 + c01 <= need; ++c01) {
            for (int c10 = 0; c00 + c01 + c10 <= need; ++c10) {
                int c11 = need - c00 - c01 - c10;
                if ((c01 + c11) % 2 == f) {
                    ans += dp[q1][c00][c01][c10];
                    ans %= mod;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}