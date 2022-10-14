#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

vector<int> get_primes(int n) {
    vector<int> primes;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            primes.push_back(p); // wtf ...
            do {
                n /= p;
            } while (n % p == 0);
        }
    }
    if (n > 1) {
        primes.push_back(n);
    }
    return primes;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int64_t p, q;
        cin >> p >> q;
        int64_t ans = 0;
        for (int d : get_primes(q)) {
            int64_t a = p;
            while (a % q == 0) {
                a /= d;
            }
            ans = max(ans, a);
        }
        cout << ans << '\n';
    }
    return 0;
}