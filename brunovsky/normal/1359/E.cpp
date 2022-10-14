#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

long gcd(long a, long b, long& x, long& y) {
    long xn = 1, yn = 0;
    x = 0, y = 1;
    while (a != 0) {
        long q = b / a;
        b = b % a;
        x = x - q * xn, y = y - q * yn;
        swap(a, b), swap(x, xn), swap(y, yn);
    }
    if (b < 0) {
        b = -b, x = -x, y = -y;
    }
    return b;
}

long modfac(int n, long m) {
    long f = 1;
    while (n > 1) {
        f = (f * n--) % m;
    }
    return f;
}

long invmod(long a, long m) {
    long x, y, g = gcd(a, m, x, y);
    (void)g, assert(g == 1);
    x = x % m;
    return x >= 0 ? x : x + m;
}

long choosemod(long n, long k, long m) {
    if (k < 0 || k > n)
        return 0;
    long x = modfac(n, m);
    x = x * invmod(modfac(n - k, m), m) % m;
    x = x * invmod(modfac(k, m), m) % m;
    return x;
}

constexpr long mod = 998244353;

auto solve() {
    int N, K;
    cin >> N >> K;
    long ans = 0;
    for (int g = 1; g <= N; g++) {
        int k = N / g;
        if (K <= k) {
            ans = (ans + choosemod(k - 1, K - 1, mod)) % mod;
        } else {
            break;
        }
    }
    return ans;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    cout << solve() << endl;
    return 0;
}