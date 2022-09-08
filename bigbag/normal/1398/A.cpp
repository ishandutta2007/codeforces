#include <bits/stdc++.h>

using namespace std;

const int max_n = 50555, inf = 1000111222;

int t, n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        if (a[0] + a[1] <= a[n - 1]) {
            printf("1 2 %d\n", n);
        } else {
            puts("-1");
        }
    }
    return 0;
}