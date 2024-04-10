#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 888, inf = 1111111111;

int n, f[max_n], ans[max_n], a[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    n *= 2;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            scanf("%d", &a[i][j]);
            a[j][i] = a[i][j];
        }
    }
    int res = n;
    while (res) {
        for (int i = 1; i <= n; ++i) {
            if (ans[i] == 0) {
                int mx = -1;
                for (int j = 1; j <= n; ++j) {
                    if (i != j && ans[j] == 0 && mx < a[i][j]) {
                        mx = a[i][j];
                        f[i] = j;
                    }
                }
            }
        }
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                if (f[j] == k && f[k] == j && ans[j] == 0 && ans[k] == 0) {
                    ans[j] = k;
                    ans[k] = j;
                    res -= 2;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    return 0;
}