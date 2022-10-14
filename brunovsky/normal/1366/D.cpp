#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

vector<int> lp, nxt;

auto least_prime_sieve(int N) {
    vector<int> primes;
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

auto factor_primes(int n) {
    unordered_map<int, int> primes;
    while (n > 1) {
        primes[lp[n]]++, n = nxt[n];
    }
    return primes;
}

auto get_divisors(const unordered_map<int, int>& factors, bool one, bool self) {
    vector<int> divs = {1};
    for (const auto& [p, e] : factors) {
        int D = divs.size();
        divs.resize(D * (e + 1));
        for (int n = 1; n <= e; n++) {
            for (int d = 0; d < D; d++) {
                divs[d + n * D] = divs[d + (n - 1) * D] * p;
            }
        }
    }
    if (!one) {
        divs.erase(begin(divs));
    }
    if (!self && !divs.empty()) {
        divs.erase(begin(divs) + (divs.size() - 1));
    }
    return divs;
}

auto solve() {
    int N;
    cin >> N;
    vector<array<int, 2>> ans(N, {-1, -1});
    unordered_map<int, int> cache;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        if (cache.count(A)) {
            ans[i] = ans[cache.at(A)];
            continue;
        } else {
            cache[A] = i;
        }
        auto divs = get_divisors(factor_primes(A), false, true);
        for (int k = 0, D = divs.size(); k < D; k++) {
            for (int j = k; j < D; j++) {
                int u = divs[k], v = divs[j];
                if (gcd(u + v, A) == 1) {
                    ans[i] = {u, v};
                    goto done;
                }
            }
        }

    done:
        continue;
    }
    for (int i = 0; i < N; i++) {
        cout << (i ? " " : "") << ans[i][0];
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << (i ? " " : "") << ans[i][1];
    }
    cout << endl;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    least_prime_sieve(10'000'000);
    solve();
    return 0;
}