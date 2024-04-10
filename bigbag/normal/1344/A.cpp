#include <bits/stdc++.h>

using namespace std;

const int max_n = 202222, inf = 1000111222;
const int k = 5;

int t, n, a[max_n];
bool f[k * max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            a[i] %= n;
        }
        const int m = k * n;
        memset(f, 0, m);
        for (int i = 0; i < m; ++i) {
            int to = i + a[i % n];
            if (0 <= to && to < m) {
                f[to] = 1;
            }
        }
        bool ok = 1;
        for (int i = n; i < (k - 1) * n; ++i) {
            if (!f[i]) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}