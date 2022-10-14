#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto factor_map(int n) {
    unordered_map<int, int> primes;
    for (int p = 2; p * p <= n; p++) {
        while (n % p == 0) {
            primes[p]++;
            n = n / p;
        }
    }
    if (n > 1) {
        primes[n]++;
    }
    return primes;
}

auto get_divisors(const unordered_map<int, int>& factors, bool one = false,
                  bool self = false) {
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

vector<int> many;

auto solve() {
    int N, K;
    cin >> N >> K;
    auto divs = get_divisors(factor_map(K), true, true);
    sort(rbegin(divs), rend(divs));
    string s;
    cin >> s;
    many.assign(26, 0);
    for (char c : s) {
        many[c - 'a']++;
    }
    int ans = 0;
    for (int period : divs) {
        // try to make a necklace with period
        // how long can it be?
        int maxrep = N / period;
        int maxlen = maxrep * period;
        if (ans >= maxlen) {
            continue;
        }
        int L = 1, R = maxrep;
        while (L <= R) {
            int reps = (L + R) / 2;
            // can we make reps repetitions?
            int can = 0;
            for (int i = 0; i < 26; i++) {
                can += many[i] / reps;
            }
            if (can >= period) {
                L = reps + 1;
            } else {
                R = reps - 1;
            }
        }
        ans = max(ans, (L - 1) * period);
    }
    return ans;
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