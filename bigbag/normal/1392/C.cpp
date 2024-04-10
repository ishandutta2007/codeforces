#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

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
        long long ans = 0;
        for (int i = n - 1; i > 0; --i) {
            if (a[i] < a[i - 1]) {
                ans += a[i - 1] - a[i];
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}