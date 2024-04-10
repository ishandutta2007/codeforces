#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int n, a, b, f;
int g[max_n][max_n];

void write() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d", g[i][j]);
        }
        printf("\n");
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &a, &b);
    if (a > 1 && b > 1) {
        puts("NO");
        return 0;
    }
    if (a == 1 && b == 1) {
        if (n == 2 || n == 3) {
            puts("NO");
            return 0;
        }
        puts("YES");
        for (int i = 0; i + 1 < n; ++i) {
            g[i][i + 1] = 1;
            g[i + 1][i] = 1;
        }
        write();
        return 0;
    }
    puts("YES");
    if (a < b) {
        f = 1;
        swap(a, b);
    }
    for (int i = 0; i < n - a + 1; ++i) {
        for (int j = 0; j < n - a + 1; ++j) {
            if (i != j) {
                g[i][j] = 1;
            }
        }
    }
    if (f) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                g[i][j] ^= 1;
                if (i == j) {
                    g[i][j] = 0;
                }
            }
        }
    }
    write();
    return 0;
}