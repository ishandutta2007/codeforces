#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int n, m, l[max_n][max_n], r[max_n][max_n], up[max_n][max_n], down[max_n][max_n];
char a[max_n][max_n], b[max_n][max_n];
int x[max_n][max_n], y[max_n][max_n];

int getl(char c) {
    if (c == '.') {
        return 0;
    }
    return -1;
}

int Q;

int getr(char c) {
    if (c == '.') {
        return Q - 1;
    }
    return Q;
}

void prec() {
    Q = m;
    for (int i = 0; i < n; ++i) {
        l[i][0] = getl(a[i][0]);
        for (int j = 1; j < m; ++j) {
            l[i][j] = l[i][j - 1];
            if (a[i][j] == '.') {
                l[i][j] = j;
            }
        }

        r[i][m - 1] = getr(a[i][m - 1]);
        for (int j = m - 2; j >= 0; --j) {
            r[i][j] = r[i][j + 1];
            if (a[i][j] == '.') {
                r[i][j] = j;
            }
        }
    }

    Q = n;
    for (int i = 0; i < m; ++i) {
        up[0][i] = getl(a[0][i]);
        for (int j = 1; j < n; ++j) {
            up[j][i] = up[j - 1][i];
            if (a[j][i] == '.') {
                up[j][i] = j;
            }
        }

        down[n - 1][i] = getr(a[n - 1][i]);
        for (int j = n - 2; j >= 0; --j) {
            down[j][i] = down[j + 1][i];
            if (a[j][i] == '.') {
                down[j][i] = j;
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", a[i]);
        for (int j = 0; j < m; ++j) {
            b[i][j] = '.';
        }
    }
    prec();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int rad = min({j - l[i][j], r[i][j] - j, i - up[i][j], down[i][j] - i});
            if (rad <= 1) {
                continue;
            }
            x[i][j - rad + 1] += 1;
            x[i][j + rad] -= 1;
            y[i - rad + 1][j] += 1;
            y[i + rad][j] -= 1;
            ++ans;
        }
    }
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = 0; j < m; ++j) {
            cur += x[i][j];
            if (cur > 0) {
                b[i][j] = '*';
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        int cur = 0;
        for (int j = 0; j < n; ++j) {
            cur += y[j][i];
            if (cur > 0) {
                b[j][i] = '*';
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] != b[i][j]) {
                puts("-1");
                return 0;
            }
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int rad = min({j - l[i][j], r[i][j] - j, i - up[i][j], down[i][j] - i});
            if (rad <= 1) {
                continue;
            }
            printf("%d %d %d\n", i + 1, j + 1, rad - 1);
        }
    }
    return 0;
}