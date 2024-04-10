#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

int t, n, k, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n * k; ++i) {
            scanf("%d", &a[i]);
        }
        long long ans = 0;
        for (int i = n * k - 1 - n / 2, j = 0; j < k; i -= n / 2 + 1, ++j) {
            ans += a[i];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}