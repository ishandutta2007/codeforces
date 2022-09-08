#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, a[max_n], dp[max_n][2][2][2];

void get_dp() {
    for (int n = 0; n < max_n; ++n) {
        for (int c0 = 0; c0 < 2; ++c0) {
            for (int f0 = 0; f0 < 2; ++f0) {
                for (int f1 = 0; f1 < 2; ++f1) {
                    if (((n % 2) ^ f0 ^ f1) == 0) {
                        continue;
                    }
                    if (n == 0) {
                        dp[n][c0][f0][f1] = f0;
                        continue;
                    }
                    int res = 0;
                    if (!dp[n - 1][c0][f1][f0 ^ 1]) {
                        res = 1;
                    }
                    if (c0 && !dp[n][c0 ^ 1][f1][f0]) {
                        res = 1;
                    }
                    dp[n][c0][f0][f1] = res;
                }
            }
        }
    }
}

bool get_bit(int x, int pos) {
    return (x >> pos) & 1;
}

bool solve(int id) {
    int c1 = 0;
    for (int i = 0; i < n; ++i) {
        c1 += get_bit(a[i], id);
    }
    int c0 = n - c1;
    return dp[c1][c0 % 2][0][0];
    if (c1 == 1) {
        return 1;
    }
    if (c0 % 2 == 0) {
        return 0;
    }
    return 1;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_dp();
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int x = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            x ^= a[i];
        }
        int id = -1;
        for (int i = 30; i >= 0; --i) {
            if (get_bit(x, i)) {
                id = i;
                break;
            }
        }
        if (id == -1) {
            puts("DRAW");
            continue;
        }
        if (solve(id)) {
            puts("WIN");
        } else {
            puts("LOSE");
        }
    }
    return 0;
}