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
        int mx = 0, one = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            mx = max(mx, a[i]);
            one |= a[i] == x;
        }
        if (one) {
            puts("1");
        } else {
            printf("%d\n", max(2, (x + mx - 1) / mx));
        }
    }
    return 0;
}