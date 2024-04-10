#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;

int n, m, a[max_n];
long long sum[max_n], dp[max_n];

long long get_sum(int l, int r) {
    if (l == 0) {
        return sum[r];
    }
    return sum[r] - sum[l - 1];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    reverse(a, a + n);
    sum[0] = a[0];
    for (int i = 1; i < n; ++i) {
        sum[i] = a[i] + sum[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        dp[i] = get_sum(i, min(n - 1, i + m - 1));
        if (i + m < n) {
            dp[i] += dp[i + m] + get_sum(i + m, n - 1);
        }
        printf("%I64d ", dp[i]);
    }
    puts("");
    return 0;
}