#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + 2 * n);
    long long ans = 1LL * (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
    for (int i = 1; i < n; ++i) {
        long long x = a[n + i - 1] - a[i];
        long long y = a[2 * n - 1] - a[0];
        ans = min(ans, x * y);
    }
    printf("%I64d\n", ans);
    return 0;
}