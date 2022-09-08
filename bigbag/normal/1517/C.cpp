/**
 *  created: 23/04/2021, 17:56:25
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 555, inf = 1000111222;

int n, p[max_n], a[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        int x = i, y = i;
        for (int j = 0; j < p[i]; ++j) {
            a[x][y] = p[i];
            if (j + 1 == p[i]) {
                break;
            }
            if (x + 1 < n && !a[x + 1][y]) {
                ++x;
            } else {
                --y;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf("%d ", a[i][j]);
        }
        puts("");
    }
    return 0;
}