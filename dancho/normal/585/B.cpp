#include <cstdio>
#include <cstring>

int n, k;
char x[128][128];

int us[128][128];

bool go(int r, int c) {
    if (us[r][c] != -1) return us[r][c];
    if (c >= n) {
        return (us[r][c] = 1);
    }
    int f0, f1, f2;
    f0 = 1;
    f1 = 1;
    f2 = 1;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            if (x[i][j] != '.' && x[i][j] != 's') {
                int ni, nj;
                ni = i;
                nj = j - 2 * c;
                if (ni == r && nj == c) {
                    return (us[r][c] = 0);
                }
                if (ni == r - 1 && nj == c + 1) {
                    f0 = 0;
                }
                if (ni == r && nj == c + 1) {
                    f1 = 0;
                }
                if (ni == r + 1 && nj == c + 1) {
                    f2 = 0;
                }
                if (c) {
                    nj = j - 2 * c + 1;
                    if (ni == r && nj == c) {
                        return (us[r][c] = 0);
                    }
                    // if (ni == r - 1 && nj == c + 1) {
                    //     f0 = 0;
                    // }
                    // if (ni == r && nj == c + 1) {
                    //     f1 = 0;
                    // }
                    // if (ni == r + 1 && nj == c + 1) {
                    //     f2 = 0;
                    // }
                }
            }
        }
    }

    if (f1) {
        if (r - 1 >= 0) {
            if (go(r - 1, c + 1) == 1 && f0) {
                return (us[r][c] = 1);
            }
        }
        if (go(r, c + 1) && f1) {
            return (us[r][c] = 1);
        }
        if (r + 1 < k) {
            if (go(r + 1, c + 1) && f2) {
                return (us[r][c] = 1);
            }
        }
    }
    return (us[r][c] = 0);
}

int main() {
    int t, T;
    scanf("%d", &T);
    for (t = 0; t < T; ++t) {
        scanf("%d %d", &n, &k);
        k = 3;
        for (int i = 0; i < k; ++i) {
            scanf("%s", x[i]);
        }
        memset(us, -1, sizeof(us));
        bool ok = false;
        for (int i = 0; i < k; ++i) {
            if (x[i][0] == 's') {
                if (go(i, 0)) {
                    ok = true;
                }
            }
        }
        if (ok) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}