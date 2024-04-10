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

const int max_n = 33, inf = 1111111111;

int n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    if (n >= 24) {
        printf("YES\n3 - 1 = 2\n2 - 2 = 0\n");
        for (int i = 4; i <= n; ++i) {
            if (i != 24) {
                printf("0 * %d = 0\n", i);
            }
        }
        printf("0 + 24 = 24\n");
        return 0;
    }
    if (n >= 13 && n <= 20) {
        printf("YES\n3 - 1 = 2\n2 - 2 = 0\n");
        printf("%d + %d = 24\n", n, 24 - n);
        for (int i = 4; i < n; ++i) {
            if (i != 24 - n) {
                printf("0 * %d = 0\n", i);
            }
        }
        printf("0 + 24 = 0\n");
        return 0;
    }
    if (n > 20) {
        printf("YES\n10 - 6 = 4\n4 - 4 = 0\n");
        printf("%d + %d = 24\n", n, 24 - n);
        for (int i = 1; i < n; ++i) {
            if (i != 4 && i != 6 && i != 10 && i != 24 - n) {
                printf("0 * %d = 0\n", i);
            }
        }
        printf("0 + 24 = 0\n");
        return 0;
    }
    if (n <= 3) {
        printf("NO\n");
        return 0;
    }
    if (n == 4) {
        printf("YES\n1 * 2 = 2\n3 * 4 = 12\n2 * 12 = 24\n");
        return 0;
    }
    if (n == 5) {
        printf("YES\n3 * 5 = 15\n2 * 4 = 8\n15 + 8 = 23\n23 + 1 = 24\n");
        return 0;
    }
    printf("YES\n4 * 6 = 24\n5 - 3 = 2\n2 - 2 = 0\n0 * 1 = 0\n");
    for (int i = 7; i <= n; ++i) {
        printf("0 * %d = 0\n", i);
    }
    printf("0 + 24 = 24\n");
    return 0;
}