#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int n, a[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    int cur = 0;
    for (int i = 0; i < n; i += 4) {
        for (int j = 0; j < n; j += 4) {
            for (int x = 0; x < 4; ++x) {
                for (int y = 0; y < 4; ++y) {
                    a[i + x][j + y] = cur++;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", a[i][j]);
        }
        puts("");
    }
    return 0;
}