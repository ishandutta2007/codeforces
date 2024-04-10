#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111, inf = 111111111;

int n, m, l, r, l1, r1;
char c, a[max_n][max_n], ans[2555];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    cin >> c;
    scanf("\n");
    for (int i = 0; i < n; ++i) {
        gets(a[i]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == c) {
                if (j > 0 && a[i][j - 1] != '.') ans[a[i][j - 1]] = 1;
                if (j < m - 1 && a[i][j + 1] != '.') ans[a[i][j + 1]] = 1;
                if (i > 0 && a[i - 1][j] != '.') ans[a[i - 1][j]] = 1;
                if (i < n - 1 && a[i + 1][j] != '.') ans[a[i + 1][j]] = 1;
            }
        }
    }
    int ans1 = 0;
    for (int i = 0; i < 2222; ++i) {
        if (i != c) ans1 += ans[i];
    }
    cout << ans1;
    return 0;
}