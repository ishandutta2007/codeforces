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

auto count(int n) {
    if (n == 1) {
        return 0;
    } else if (n == lp[n]) {
        return 1;
    } else {
        return 2;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    least_prime_sieve(1'000'000);

    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;

        vector<int> a(N);
        vector<vector<vector<int>>> b(E);
        for (int x = 0; x < E; x++) {
            b[x].push_back({0});
        }
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            int c = a[i] = count(a[i]);
            int x = i % E;
            if (c == 2) {
                b[x].push_back({0});
            } else if (c == 0) {
                b[x].back().back()++;
            } else {
                b[x].back().push_back(0);
            }
        }

        int64_t ans = 0;

        for (int x = 0; x < E; x++) {
            for (const auto& run : b[x]) {
                int R = run.size();
                for (int i = 0; i + 1 < R; i++) {
                    ans += 1LL * (run[i] + 1) * (run[i + 1] + 1) - 1;
                }
            }
        }

        cout << ans << '\n';
    }
    return 0;
}

// Don't fucking misread problems again you dumb fucking shit