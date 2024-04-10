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
    int N;
    cin >> N;
    vector<int> A(N);
    unordered_map<int, int> cnt;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        cnt[A[i]]++;
    }
    sort(begin(A), end(A));
    A.erase(unique(begin(A), end(A)), end(A));
    unordered_map<int, int> dp;
    int ans = 0;
    for (int n : A) {
        auto divs = get_divisors(factor_primes(n));
        dp[n] = cnt[n];
        for (int x : divs) {
            if (x != n && dp.count(x)) {
                dp[n] = max(dp[n], dp[x] + cnt[n]);
            }
        }
        ans = max(dp[n], ans);
    }
    return N - ans;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    least_prime_sieve(200'001);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}