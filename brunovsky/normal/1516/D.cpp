#include <bits/stdc++.h>

using namespace std;

// *****

constexpr int MAXN = 100'000;
vector<int> primes, lp;

void least_prime_sieve(int N) {
    lp.assign(N + 1, 0);

    for (int P = 0, n = 2; n <= N; n++) {
        if (lp[n] == 0) {
            lp[n] = n, primes.push_back(n), P++;
        }
        for (int i = 0; i < P && primes[i] <= lp[n] && n * primes[i] <= N; ++i) {
            lp[n * primes[i]] = primes[i];
        }
    }
}

vector<int> get_primes(int n) {
    vector<int> factors;
    while (n > 1) {
        int p = lp[n];
        factors.push_back(p);
        do {
            n /= p;
        } while (n > 1 && lp[n] == p);
    }
    return factors;
}

auto solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<bool> seen(MAXN + 1, false);
    vector<vector<int>> jmp;
    jmp.emplace_back(N + 1, N);
    int i = 0, j = 0;

    while (i < N) {
        while (j < N) {
            auto primes = get_primes(A[j]);
            bool ok = none_of(begin(primes), end(primes), [&](int p) { return seen[p]; });
            if (ok) {
                for (int p : primes) {
                    seen[p] = true;
                }
                j++;
            } else {
                break;
            }
        }
        for (int p : get_primes(A[i])) {
            seen[p] = false;
        }
        jmp[0][i] = j, i++;
    }

    int S = 0;
    while (jmp[S][0] != N) {
        jmp.emplace_back(N + 1, N), S++;
        for (int n = 0; n < N; n++) {
            jmp[S][n] = jmp[S - 1][jmp[S - 1][n]];
        }
    }

    for (int q = 0; q < Q; q++) {
        int l, r;
        cin >> l >> r, l--;
        int ans = 1;
        for (int b = S; b >= 0; b--) {
            if (jmp[b][l] < r) {
                ans += 1 << b, l = jmp[b][l];
            }
        }
        cout << ans << endl;
    }
    return 0;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    least_prime_sieve(MAXN);
    solve();
    return 0;
}