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

const int max_n = 1000011, mod = 1000000007;

int power(int a, int b, int mod) {
    if (b == 0) {
        return 1 % mod;
    }
    if (b % 2 == 0) {
        return power((1LL * a * a) % mod, b / 2, mod);
    }
    return (1LL * a * power(a, b - 1, mod)) % mod;
}

int ans, n, k, q, a[max_n];
int f[max_n], rf[max_n];
vector<int> v, d[max_n];

int get_c(int n, int k) {
    if (n < k) {
        return 0;
    }
    int res = (1LL * f[n] * rf[k]) % mod;
    res = (1LL * res * rf[n - k]) % mod;
    return res;
}

int coef[max_n];

void rec(int x, int q, int cnt) {
    if (cnt % 2) {
        coef[x] += mod - q;
        coef[x] %= mod;
    } else {
        coef[x] += q;
        coef[x] %= mod;
    }
    for (int i = 2; i * x < max_n; ++i) {
        rec(i * x, q, cnt + 1);
    }
}

void proc() {
    for (int i = 1; i < max_n; ++i) {
        coef[i] += i;
        coef[i] %= mod;
        for (int j = 2 * i; j < max_n; j += i) {
            coef[j] += mod - coef[i];
            coef[j] %= mod;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    proc();
    f[0] = rf[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        f[i] = (1LL * f[i - 1] * i) % mod;
        rf[i] = power(f[i], mod - 2, mod);
    }
    for (int x = 1; x < max_n; ++x) {
        v.clear();
        for (int j = 1; j * j <= x; ++j) {
            if (x % j == 0) {
                d[x].push_back(j);
                if (j < x / j) {
                    v.push_back(x / j);
                }
            }
        }
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); ++i) {
            d[x].push_back(v[i]);
        }
        reverse(d[x].begin(), d[x].end());
    }
    scanf("%d%d%d", &n, &k, &q);
    ++n;
    --q;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        for (int j = 0; j < d[x].size(); ++j) {
            ++a[d[x][j]];
        }
    }
    int ans = 0;
    for (int i = 1; i < max_n; ++i) {
        int res = (1LL * coef[i] * get_c(a[i], k)) % mod;
        ans += res;
        ans %= mod;
    }
    printf("%d\n", ans);
    while (q--) {
        int x;
        scanf("%d", &x);
        for (int i = 0; i < d[x].size(); ++i) {
            int q = d[x][i];
            int res = (1LL * coef[q] * get_c(a[q], k)) % mod;
            ans += mod - res;
            ans %= mod;
            ++a[q];
            res = (1LL * coef[q] * get_c(a[q], k)) % mod;
            ans += res;
            ans %= mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}