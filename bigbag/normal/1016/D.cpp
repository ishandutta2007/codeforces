#include <bits/stdc++.h>

using namespace std;

const int max_n = 111, inf = 1000111222;

int n, m, x, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        x ^= a[i];
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
        x ^= b[i];
    }
    if (x) {
        puts("NO");
    } else {
        puts("YES");
        for (int i = 0; i + 1 < n; ++i) {
            for (int j = 0; j + 1 < m; ++j) {
                printf("0 ");
            }
            printf("%d\n", a[i]);
        }
        x = a[n - 1];
        for (int i = 0; i + 1 < m; ++i) {
            printf("%d ", b[i]);
            x ^= b[i];
        }
        printf("%d\n", x);
    }
    return 0;
}