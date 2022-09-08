#include <bits/stdc++.h>

using namespace std;

const int max_n = 202222, inf = 1000111222;

int n, m, k, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int full = m / (k + 1);
    m %= (k + 1);
    long long ans = 1LL * full * (1LL * k * a[n - 1] + a[n - 2]) + 1LL * m * a[n - 1];
    printf("%I64d\n", ans);
    return 0;
}