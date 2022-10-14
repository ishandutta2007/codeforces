#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

vector<int> primes, lp, nxt;

// Compute least prime divisors and n/lp[n] of all n<=N. O(N)
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
}

auto get_primes(int n) {
    map<int, int> primes;
    while (n > 1) {
        primes[lp[n]]++, n = nxt[n];
    }
    return primes;
}

template <typename T>
auto get_divisors(const map<T, int>& factors) {
    vector<T> divs = {1};
    for (const auto& [p, e] : factors) {
        int D = divs.size();
        divs.resize(D * (e + 1));
        for (int n = 1; n <= e; n++) {
            for (int d = 0; d < D; d++) {
                divs[d + n * D] = divs[d + (n - 1) * D] * p;
            }
        }
    }
    sort(begin(divs), end(divs));
    return divs;
}

void solve() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    s = '1' + s;
    int64_t cost = 0;
    vector<int8_t> ok(N + 1, true);
    for (int n = 1; n <= N; n++) {
        if (s[n] == '0') {
            for (int d : get_divisors(get_primes(n))) {
                if (ok[d]) {
                    cost += d;
                    break;
                }
            }
        } else {
            for (int d : get_divisors(get_primes(n))) {
                ok[d] = false;
            }
        }
    }
    cout << cost << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    least_prime_sieve(1'000'000);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}