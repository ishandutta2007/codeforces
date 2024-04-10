#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 333333, mod = 1000000007;

int power(int a, int b, int mod) {
    if (b == 0) {
        return 1 % mod;
    }
    if (b % 2 == 0) {
        return power((1LL * a * a) % mod, b / 2, mod);
    }
    return (1LL * a * power(a, b - 1, mod)) % mod;
}

int n, a[max_n], pw[max_n], sum[2][max_n], rpw[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    pw[0] = rpw[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pw[i] = (2LL * pw[i - 1]) % mod;
        rpw[i] = power(pw[i], mod - 2, mod);
    }
    for (int i = n - 1; i >= 0; --i) {
        sum[0][i] = pw[i];
        sum[1][i] = (1LL * pw[i] * a[i]) % mod;
        if (i < n) {
            sum[0][i] += sum[0][i + 1];
            sum[1][i] += sum[1][i + 1];
        }
        sum[0][i] %= mod;
        sum[1][i] %= mod;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x = (sum[1][i + 1] + mod - (1LL * a[i] * sum[0][i + 1]) % mod) % mod;
        ans += (1LL * x * rpw[i + 1]) % mod;
        ans %= mod;
    }
    printf("%d\n", ans);
    return 0;
}