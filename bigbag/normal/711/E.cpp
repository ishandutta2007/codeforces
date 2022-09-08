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

const int max_n = 1, mod = 1000003;

long long n, x, k;

int power(int a, long long b, int mod) {
    if (b == 0) {
        return 1 % mod;
    }
    if (b % 2 == 0) {
        return power((1LL * a * a) % mod, b / 2, mod);
    }
    return (1LL * a * power(a, b - 1, mod)) % mod;
}

void solve(long long n, long long k) {
    x = 1LL << n;
    if (x <= k) {
        cout << "1/1 ";
        return;
    }
    long long a = (1LL << (n * k));
    long long b = a;
    long long q = 1;
    for (int i = 1; i <= k; ++i) {
        q *= x;
        --x;
    }
    a -= q;
    q = __gcd(a, b);
    a /= q;
    b /= q;
    a %= mod;
    b %= mod;
    cout << "" << a << "/" << b << " ";
}

bool check(long long n, long long k) {
    if (n > 60) {
        return false;
    }
    return (1LL << n) < k;
}

long long inv;

void solve2(long long n, long long k) {
    if (check(n, k)) {
        cout << "1 1" << endl;
        return;
    }
    long long q = n;
    --k;
    for (long long i = 2; i <= k; i *= 2) {
        q += k / i;
    }
    ++k;
    long long B = power(2, n, mod);
    B = power(B, k, mod);
    long long C = power(2, q, mod);
    C = power(C, mod - 2, mod);
    B = (B * C) % mod;
    long long A = B;
    if (k <= 10 * mod) {
        long long x = power(2, n, mod);
        long long res = 1;
        for (int i = 1; i < k; ++i) {
            --x;
            if (x < 0) {
                x += mod;
            }
            long long y = x, qqq = i;
            while (qqq % 2 == 0) {
                qqq /= 2;
                y = (y * inv) % mod;
            }
            res = (res * y) % mod;
        }
        A = (A + mod - res) % mod;
    }
    cout << A << " " << B << endl;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    inv = power(2, mod - 2, mod);
    cin >> n >> k;
    solve2(n, k);
    return 0;
}