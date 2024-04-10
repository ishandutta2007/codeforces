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

const int max_n = 555, inf = 1111111111;

int n, k, ans, x, a[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    x = n * n;
    --k;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j >= k; --j) {
            a[i][j] = x;
            --x;
        }
    }
    x = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 0) {
                a[i][j] = x;
                ++x;
            }
            if (j == k) {
                ans += a[i][j];
            }
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}