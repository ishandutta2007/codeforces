#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, mod = 998244353;

int n;

int triv(int n) {
    vector<int> v, all;
    int need = 0;
    for (int i = 1; i <= n; ++i) {
        v.push_back(i);
        need += i;
    }
    do {
        for (int x : v) {
            all.push_back(x);
        }
    } while (next_permutation(v.begin(), v.end()));
    int res = 0;
    for (int i = 0; i + n <= all.size(); ++i) {
        if (accumulate(all.begin() + i, all.begin() + i + n, 0) == need) {
            ++res;
        }
    }
    return res;
}

int f[max_n], rf[max_n];

int mul(int x, int y) {
    return (1LL * x * y) % mod;
}

int power(int a, int b, int mod) {
    if (b == 0) {
        return 1 % mod;
    }
    if (b % 2 == 0) {
        return power((1LL * a * a) % mod, b / 2, mod);
    }
    return (1LL * a * power(a, b - 1, mod)) % mod;
}

void get_all_f() {
    f[0] = rf[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        f[i] = (1LL * i * f[i - 1]) % mod;
    }
    rf[max_n - 1] = power(f[max_n - 1], mod - 2, mod);
    for (int i = max_n - 2; i > 0; --i) {
        rf[i] = (1LL * (i + 1) * rf[i + 1]) % mod;
    }
}

int get_c(int n, int k) {
    if (n < k) {
        return 0;
    }
    int res = (1LL * f[n] * rf[k]) % mod;
    return (1LL * res * rf[n - k]) % mod;
}

int solve(int n) {
    int res = 1;
    for (int i = 0; i < n; ++i) {
        res += mul(get_c(n, i), mul(f[i], f[n - i] - 1));
        res %= mod;
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_f();
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}