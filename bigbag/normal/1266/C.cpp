#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int n, m;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    if (n == 1 && m == 1) {
        puts("0");
        return 0;
    }
    if (m == 1) {
        for (int i = 0; i < n; ++i) {
            printf("%d\n", i + 2);
        }
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = i + 1;
            x *= (n + j + 1);
            printf("%d ", x);
        }
        puts("");
    }
    return 0;
}