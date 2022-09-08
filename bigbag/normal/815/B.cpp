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

const int max_n = 200222, mod = 1000000007;//!!!!

int power(int a, int b, int mod) {
    if (b == 0) {
        return 1 % mod;
    }
    if (b % 2 == 0) {
        return power((1LL * a * a) % mod, b / 2, mod);
    }
    return (1LL * a * power(a, b - 1, mod)) % mod;
}

int f[max_n], rf[max_n];

void get_all_f() {
    f[0] = rf[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        f[i] = (1LL * i * f[i - 1]) % mod;
        rf[i] = power(f[i], mod - 2, mod);
    }
}

int get_c(int n, int k) {
    if (n < k) {
        return 0;
    }
    int res = (1LL * f[n] * rf[k]) % mod;
    return (1LL * res * rf[n - k]) % mod;
}

int n, a[max_n];

int solve1() {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int k = 0;
        if (i % 2 == 0) {
            k = get_c(n / 2, i / 2);
        } else {
        }
        res += (1LL * k * a[i]) % mod;
        res %= mod;
    }
    return res;
}

int solve2() {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += (1LL * get_c(n / 2 - 1, i / 2) * a[i]) % mod;
        res %= mod;
    }
    return res;
}

int solve3() {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int k = get_c(n / 2 - 1, i / 2);
        if (i % 2 == 0) {
        } else {
            k = mod - k;
        }
        res += (1LL * k * a[i]) % mod;
        res %= mod;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_f();
    scanf("%d", &n);
    int q1 = 0, q2 = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    if (n % 4 == 1) {
        cout << solve1() << endl;
    } else if (n % 4 == 2) {
        cout << solve2() << endl;
    } else if (n % 4 == 0) {
        cout << solve3() << endl;
    } else {
        --n;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                a[i] = (a[i] + a[i + 1]) % mod;
            } else {
                a[i] = (a[i] - a[i + 1] + mod) % mod;
            }
        }
        cout << solve2() << endl;
    }
    return 0;
}