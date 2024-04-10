#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

long phi(long n) {
    long tot = 1;
    if ((n & 1) == 0) {
        n >>= 1;
        while ((n & 1) == 0) {
            tot <<= 1;
            n >>= 1;
        }
    }
    for (long p = 3; p * p <= n; p += 2) {
        if ((n % p) == 0) {
            tot *= p - 1;
            n = n / p;
            while ((n % p) == 0) {
                tot *= p;
                n = n / p;
            }
        }
    }
    tot *= n > 1 ? n - 1 : 1;
    return tot;
}

auto solve() {
    long a, m;
    cin >> a >> m;
    long g = gcd(a, m);
    return phi(m / g);
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}