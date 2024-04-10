/**
 *  created: 18/02/2021, 16:39:19
**/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 1011, inf = 1000111222;

int t, n, x[max_n], y[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &x[i], &y[i]);
        }
        sort(x, x + n);
        sort(y, y + n);
        if (n % 2) {
            puts("1");
        } else {
            printf("%lld\n", 1LL * (x[n / 2] - x[n / 2 - 1] + 1) * (y[n / 2] - y[n / 2 - 1] + 1));
        }
    }
    return 0;
}