#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

vector<int> primes, lp, nxt;

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
    int N, M = 1, E = 1;
    cin >> N;
    while (M < N) {
        M <<= 1, E++;
    }

    vector<int> c(N), p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i], p[i]--;
    }
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }

    int ans = N;
    vector<bool> seen(N, false);
    for (int i = 0; i < N; i++) {
        if (!seen[i]) {
            vector<int> path;
            int j = i;
            do {
                path.push_back(j);
                seen[j] = true;
                j = p[j];
            } while (j != i);

            int P = path.size();
            ans = min(ans, P);
            auto pdivs = get_divisors(factor_primes(P), true, false);

            for (int jump : pdivs) {
                int times = P / jump;
                for (int offset = 0; offset < jump; offset++) {
                    vector<int> colors;
                    int k = offset;
                    do {
                        colors.push_back(c[path[k]]);
                        k += jump;
                    } while (k < P);
                    if (count(begin(colors), end(colors), colors[0]) == times) {
                        ans = min(ans, jump);
                        break;
                    }
                }
            }
        }
    }
    return ans;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    least_prime_sieve(200'000);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}