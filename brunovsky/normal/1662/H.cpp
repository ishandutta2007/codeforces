#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int bit(int n, int b) { return n >> b & 1; }

auto get_primes(int n) {
    map<int, int> primes;
    for (int p = 2; p * p <= n; p++) {
        while (n % p == 0) {
            n /= p;
            primes[p]++;
        }
    }
    if (n > 1) {
        primes[n]++;
    }
    return primes;
}

template <typename T>
auto get_divisors(const map<T, int>& factors, bool one, bool self) {
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
    if (!one) {
        divs.erase(begin(divs));
    }
    if (!self && !divs.empty()) {
        divs.erase(begin(divs) + (divs.size() - 1));
    }
    return divs;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int w, l;
        cin >> w >> l;
        vector<int> sols = {1};

        for (int m = 0; m < 16; m++) {
            int a = w - 2 + bit(m, 0) + !bit(m, 1);
            int b = l - 2 + bit(m, 1) + !bit(m, 2);
            int c = w - 2 + bit(m, 2) + !bit(m, 3);
            int d = l - 2 + bit(m, 3) + !bit(m, 0);
            int g = gcd(a, gcd(b, gcd(c, d)));
            for (int x : get_divisors(get_primes(g), false, true)) {
                sols.push_back(x);
            }
        }

        sort(begin(sols), end(sols));
        sols.erase(unique(begin(sols), end(sols)), end(sols));
        int S = sols.size();
        cout << S << ' ';
        for (int i = 0; i < S; i++) {
            cout << sols[i] << " \n"[i + 1 == S];
        }
    }
    return 0;
}