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

const int max_n = 1000111, inf = 1000111222;

int n, x, y, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 0; i * x <= n; ++i) {
        int c1 = i;
        int c2 = (n - i * x) / y;
        if (c1 * x + c2 * y == n) {
            int pos = 0;
            for (int j = 0; j < c1; ++j, pos += x) {
                for (int k = pos; k < pos + x; ++k) {
                    a[k] = k + 1;
                }
                a[pos + x - 1] = pos;
            }
            for (int j = 0; j < c2; ++j, pos += y) {
                for (int k = pos; k < pos + y; ++k) {
                    a[k] = k + 1;
                }
                a[pos + y - 1] = pos;
            }
            for (int j = 0; j < n; ++j) {
                printf("%d ", a[j] + 1);
            }
            printf("\n");
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}