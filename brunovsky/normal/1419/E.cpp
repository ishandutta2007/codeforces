#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

unordered_map<int, int> factor_primes(int n) {
    unordered_map<int, int> primes;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            primes[i]++;
            n = n / i;
        }
    }
    if (n > 1) {
        primes[n]++;
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
    auto factors = factor_primes(N);
    if (factors.size() == 2u) {
        auto [a, ac] = *factors.begin();
        auto [b, bc] = *++factors.begin();
        if (ac == 1 && bc == 1) {
            cout << a << ' ' << b << ' ' << a * b << endl;
            cout << 1 << endl;
            return;
        }
    }

    auto divs = get_divisors(factors, false, true);
    int D = divs.size(), P = factors.size();

    vector<int> primes;
    for (const auto& [p, e] : factors) {
        primes.push_back(p);
    }
    sort(begin(primes), end(primes));

    auto next = [&](int i) {
        if (P == 2) {
            return i == 0 ? primes[0] * primes[1] : N;
        } else {
            return primes[i] * primes[i + 1 == P ? 0 : i + 1];
        }
    };

    unordered_set<int> seen;
    for (int i = 0; i < P; i++) {
        seen.insert(primes[i]);
        seen.insert(next(i));
    }

    vector<int> walk;
    for (int i = 0; i < P; i++) {
        walk.push_back(primes[i]);
        for (int j = 0; j < D; j++) {
            if (!seen.count(divs[j]) && divs[j] % primes[i] == 0) {
                if (divs[j] != primes[i] && divs[j] != next(i)) {
                    walk.push_back(divs[j]);
                }
                seen.insert(divs[j]);
            }
        }
        walk.push_back(next(i));
    }
    for (int u : walk) {
        cout << u << " ";
    }
    cout << endl << 0 << endl;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        solve();
    }
    return 0;
}