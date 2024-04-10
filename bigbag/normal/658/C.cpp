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

const int max_n = 1, inf = 1111111111;

int n, d, h;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &d, &h);
    if (d > 2 * h) {
        printf("-1\n");
        return 0;
    }
    if (d == 1 && n > 2) {
        printf("-1\n");
        return 0;
    }
    if (d == 1) {
        printf("1 2\n");
        return 0;
    }
    for (int i = 1; i <= h; ++i) {
        printf("%d %d\n", i, i + 1);
    }
    if (d == h) {
        for (int i = h + 2; i <= n; ++i) {
            printf("2 %d\n", i);
        }
        return 0;
    }
    printf("1 %d\n", h + 2);
    for (int i = h + 2; i <= d; ++i) {
        printf("%d %d\n", i, i + 1);
    }
    for (int i = d + 2; i <= n; ++i) {
        printf("1 %d\n", i);
    }
    return 0;
}