#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int n, a[max_n][max_n], x[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    x[0] = sqrt(1LL * a[0][1] * a[0][2] / a[1][2]);
    printf("%d ", x[0]);
    for (int i = 1; i < n; ++i) {
        printf("%d ", a[0][i] / x[0]);
    }
    puts("");
    return 0;
}