#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int a, b, c, d;
int main() {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a > b && !c && !d) {
        if (a == b + 1) {
            printf("YES\n");
            for (int i = 1; i <= b; i ++)
                printf("0 1 ");
            printf("0");
            return 0;
        }
    }
    if (d > c && !a && !b) {
        if (d == c + 1) {
            printf("YES\n");
            for (int i = 1; i <= c; i ++)
                printf("3 2 ");
            printf("3");
            return 0;
        }
    }
    if (a > b || d > c) {
        printf("NO\n");
        return 0;
    }
    if (abs(b - a - (c - d)) > 1) {
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    int tmp = b - a - (c - d);
    if (tmp > 0) {
        printf("1 ");
    }
    for (int i = 1; i <= a; i++)
        printf("0 1 ");
    for (int i = 1;  i <= min(b - a, c - d); i ++)
        printf("2 1 ");
    for (int i = 1; i <= d; i ++)
        printf("2 3 ");
    if (tmp < 0)
        printf("2");
    return 0;
}