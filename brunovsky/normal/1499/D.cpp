#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

vector<int> primes, lp, nxt, num_prime_divisors;

auto least_prime_sieve(int N) {
    lp.assign(N + 1, 0), nxt.assign(N + 1, 0);

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

auto num_prime_divisors_sieve(int N) {
    num_prime_divisors.assign(N + 1, 0);

    for (int n = 2; n <= N; n++) {
        if (num_prime_divisors[n] == 0) {
            for (int i = 1; i * n <= N; i++) {
                num_prime_divisors[i * n]++;
            }
        }
    }

    return num_prime_divisors;
}

auto factor_primes(int n) {
    unordered_map<int, int> primes;
    while (n > 1) {
        primes[lp[n]]++, n = nxt[n];
    }
    return primes;
}

auto get_divisors(const unordered_map<int, int>& primes) {
    vector<int> divs = {1};
    for (const auto& [p, n] : primes) {
        int D = divs.size();
        divs.resize(D * (n + 1));
        for (int k = 1; k <= n; k++) {
            for (int i = 0; i < D; i++) {
                divs[i + k * D] = divs[i + (k - 1) * D] * p;
            }
        }
    }
    return divs;
}

auto solve() {
    int c, d, x;
    cin >> c >> d >> x;
    auto divsx = get_divisors(factor_primes(x));
    int ans = 0;
    for (int g : divsx) {
        // g = abc - d, a/b coprime
        if ((g + d) % c == 0) {
            int k = (g + d) / c;
            int distinct = num_prime_divisors[k];
            ans += 1 << distinct;
        }
    }
    return ans;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    least_prime_sieve(20'000'001);
    num_prime_divisors_sieve(20'000'001);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}