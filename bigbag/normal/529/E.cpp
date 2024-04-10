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

const int max_n = 5055, inf = 1111111111;

int n, k, a[max_n], f[11111111];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        f[a[i]] = 1;
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        int x;
        scanf("%d", &x);
        int res = inf;
        for (int i = 0; i < n; ++i) {
            for (int q = 1; q <= res && q <= k; ++q) {
                int y = x - a[i] * q;
                if (y < 0) {
                    break;
                }
                if (y == 0) {
                    res = min(res, q);
                    break;
                }
                for (int w = 1; w + q <= res && w + q <= k; ++w) {
                    if (y / w <= 10000000 && y % w == 0 && f[y / w] == 1) {
                        res = min(res, q + w);
                        break;
                    }
                }
            }
        }
        if (res == inf) {
            res = -1;
        }
        printf("%d\n", res);
    }
    return 0;
}