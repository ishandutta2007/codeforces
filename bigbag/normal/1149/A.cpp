#include <bits/stdc++.h>

using namespace std;

const int max_n = -1, inf = 1000111222;

int n, c[3];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    while (n--) {
        int x;
        scanf("%d", &x);
        ++c[x];
    }
    if (c[1] && c[2]) {
        printf("2 1 ");
        --c[1];
        --c[2];
    }
    while (c[2]--) {
        printf("2 ");
    }
    while (c[1]--) {
        printf("1 ");
    }
    puts("");
    return 0;
}