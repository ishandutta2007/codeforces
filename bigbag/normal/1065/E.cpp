#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, mod = 998244353;

int mul(int x, int y) {
    return (1LL * x * y) % mod;
}

int power(int x, int y) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return power(mul(x, x), y / 2);
    }
    return mul(x, power(x, y - 1));
}

int rev(int x) {
    return power(x, mod - 2);
}

int divide(int x, int y) {
    return mul(x, rev(y));
}

int n, m, A, l[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &m, &A);
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &l[i]);
    }
    int ans = power(A, n - l[m] * 2);
    for (int i = 1; i <= m; ++i) {
        int len = l[i] - l[i - 1];
        int x = (power(A, 2 * len) + mod - power(A, len)) % mod;
        int y = power(A, len);
        int z = (divide(x, 2) + y) % mod;
        ans = mul(ans, z);
    }
    printf("%d\n", ans);
    return 0;
}