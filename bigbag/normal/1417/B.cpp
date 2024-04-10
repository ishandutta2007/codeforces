#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n, x, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &x);
        int last = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            if (x % 2 == 0 && a[i] == x / 2) {
                printf("%d ", last);
                last ^= 1;
                continue;
            }
            if (a[i] <= x / 2) {
                printf("0 ");
            } else {
                printf("1 ");
            }
        }
        puts("");
    }
    return 0;
}