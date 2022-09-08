#include <bits/stdc++.h>

using namespace std;

const int max_n = 2022, mod = 1000000007;

int n, m, sum[max_n][max_n];
int dp1[max_n][max_n], add1[max_n][max_n];
int dp2[max_n][max_n], add2[max_n][max_n];
char s[max_n][max_n];

int get_sum(int lx, int ly, int rx, int ry) {
    int res = sum[rx][ry];
    if (lx) {
        res -= sum[lx - 1][ry];
    }
    if (ly) {
        res -= sum[rx][ly - 1];
    }
    if (lx && ly) {
        res += sum[lx - 1][ly - 1];
    }
    return res;
}

void add(int &x, int y) {
    x += y;
    x %= mod;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    if (n == 1 && m == 1) {
        puts("1");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
        for (int j = 0; j < m; ++j) {
            sum[i][j] = s[i][j] == 'R';
            if (j) {
                sum[i][j] += sum[i][j - 1];
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum[i][j] += sum[i - 1][j];
        }
    }
    add1[0][0] = add2[0][0] = 1;
    add1[1][0] = add2[0][1] = mod - 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp1[i][j] = add1[i][j];
            if (i) {
                add(dp1[i][j], dp1[i - 1][j]);
            }
            if (j + 1 < m) {
                int cnt = m - j - get_sum(i, j + 1, i, m - 1);
                add(add2[i][j + 1], dp1[i][j]);
                add(add2[i][j + cnt], mod - dp1[i][j]);
            }

            dp2[i][j] = add2[i][j];
            if (j) {
                add(dp2[i][j], dp2[i][j - 1]);
            }
            //cout << i << " " << j << ": " << dp1[i][j] << " " << dp2[i][j] << ",   " << add1[i][j] << " " << add2[i][j] << endl;
            if (i + 1 < n) {
                int cnt = n - i - get_sum(i + 1, j, n - 1, j);
                //cout << "$" << i << " " << j << ": " << cnt << endl;
                add(add1[i + 1][j], dp2[i][j]);
                add(add1[i + cnt][j], mod - dp2[i][j]);
            }
        }
    }
    int ans = dp1[n - 1][m - 1];
    add(ans, dp2[n - 1][m - 1]);
    printf("%d\n", ans);
    return 0;
}