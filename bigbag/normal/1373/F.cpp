#include <bits/stdc++.h>

using namespace std;

const int max_n = 2000222, inf = 1000111222;

int t, n, a[max_n], b[max_n];
long long sum[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &b[i]);
        }
        for (int i = n; i < 2 * n; ++i) {
            a[i] = a[i - n];
            b[i] = b[i - n];
        }
        a[2 * n] = b[2 * n] = 0;
        for (int i = 0; i <= 2 * n; ++i) {
            sum[i] = a[i] - b[i];
            if (i) {
                sum[i] += sum[i - 1];
            }
        }
        bool ok = sum[n - 1] <= 0;
        long long mx = sum[2 * n];
        for (int i = 2 * n - 1; i >= 0; --i) {
            long long res = mx - sum[i] - b[i];
            if (res > 0) {
                ok = false;
                break;
            }
            mx = max(mx, sum[i]);
        }
        if (ok) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}