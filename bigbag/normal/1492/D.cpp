/**
 *  created: 23/02/2021, 11:21:22
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int a, b, k;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &a, &b, &k);
    if (k == 0) {
        puts("Yes");
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < b; ++j) {
                printf("1");
            }
            for (int j = 0; j < a; ++j) {
                printf("0");
            }
            puts("");
        }
        return 0;
    }
    if (b == 1 || a == 0) {
        puts("No");
        return 0;
    }
    if (k > a + b - 2) {
        puts("No");
        return 0;
    }
    puts("Yes");
    int need1 = a + b - 1 - k;
    int need2 = a + b - 1;
    for (int i = 0; i < 2; ++i) {
        int ca = 0;
        int need = a + b - 1;
        for (int j = 0; j < a + b; ++j) {
            if (j == 0) {
                printf("1");
            } else if (j == need1) {
                printf("%d", 1 ^ i);
            } else if (j == need2) {
                printf("%d", 0 ^ i);
            } else if (ca < a - 1) {
                printf("0");
                ++ca;
            } else {
                printf("1");
            }
        }
        puts("");
    }
    return 0;
}