#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

vector<int> primes, lp, nxt;

auto least_prime_sieve(int N) {
    lp.assign(N + 1, 0), nxt.assign(N + 1, 0);
    nxt[1] = 1;

    for (int P = 0, n = 2; n <= N; n++) {
        if (lp[n] == 0) {
            lp[n] = n, primes.push_back(n), P++;
        }
        for (int i = 0; i < P && primes[i] <= lp[n] && n * primes[i] <= N; ++i) {
            lp[n * primes[i]] = primes[i], nxt[n * primes[i]] = n;
        }
    }

    return lp;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    least_prime_sieve(100'001);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> a(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> a[i];
        }
        // The number a[i] must not be divisible by some prime <= i+1.
        int64_t x = 1;
        bool busted = false;

        for (int i = 1; i <= N && !busted && x <= 1e16; i++) {
            x = lcm(x, i + 1);
            busted |= a[i] % x == 0;
            debug(i, x);
        }

        if (busted) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}