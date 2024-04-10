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
}

auto factor(int64_t n) {
    vector<int> factors;
    for (int p : primes) {
        if (n % p == 0) {
            factors.push_back(p);
            do {
                n /= p;
            } while (n % p == 0);
        }
        if (n == 1) {
            break;
        }
    }
    return factors;
}

using intd = uniform_int_distribution<int>;
mt19937 mt(random_device{}());

int different(int b1, int b2, int v1, int v2) {
    int v = intd(v1, v2)(mt);
    while (v == b1 || v == b2) {
        v = intd(v1, v2)(mt);
    }
    return v;
}

auto different(int v1, int v2) {
    int u = intd(v1, v2)(mt);
    return array<int, 2>{u, different(u, -1, v1, v2)};
}

auto QUERY(int x, int y) {
    cout << "? " << x + 1 << ' ' << y + 1 << endl;
    int64_t L;
    cin >> L;
    return L;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    least_prime_sieve(200'000);
    while (T--) {
        int N;
        cin >> N;

        if (N + 5000 < 1LL * N * (N - 1) / 2) {
            int P = 0;
            pair<int, int> who;
            for (int i = 0; i < 4999; i++) {
                auto [x, y] = different(0, N - 1);
                auto factors = factor(QUERY(x, y));
                for (int p : factors) {
                    if (P < p) {
                        P = p;
                        who = {x, y};
                    }
                }
            }
            // find out if it is who[0] or who[1]
            auto [x0, x1] = who;
            int y0 = different(x0, x1, 0, N - 1);
            int y1 = different(x0, x1, 0, N - 1);
            int64_t L0 = QUERY(x0, y0);
            int64_t L1 = QUERY(x0, y1);
            int x;
            if (L0 % P == 0 && L1 % P == 0) {
                x = x0;
            } else {
                x = x1;
            }
            vector<int> ans(N);
            ans[x] = P;
            for (int i = 0; i < N; i++) {
                if (i != x) {
                    ans[i] = QUERY(x, i) / P;
                }
            }
            cout << "! ";
            for (int i = 0; i < N; i++) {
                cout << ans[i] << " \n"[i + 1 == N];
            }
        } else {
            vector<vector<int64_t>> mat(N, vector<int64_t>(N));
            for (int i = 0; i < N; i++) {
                for (int j = i + 1; j < N; j++) {
                    mat[j][i] = mat[i][j] = QUERY(i, j);
                }
            }
            vector<int> ans(N);
            for (int i = 0; i < N; i++) {
                int64_t g = mat[i][0];
                for (int j = 0; j < N; j++) {
                    g = gcd(g, mat[i][j]);
                }
                ans[i] = g;
            }
            if (N == 3) {
                int& a = ans[0];
                int& b = ans[1];
                int& c = ans[2];
                if (a % 2 == 0 && b % 2 == 0 && c % 2 == 0) {
                    if (a == max({a, b, c})) {
                        a /= 2;
                    } else if (b == max({a, b, c})) {
                        b /= 2;
                    } else {
                        c /= 2;
                    }
                }
            }
            cout << "! ";
            for (int i = 0; i < N; i++) {
                cout << ans[i] << " \n"[i + 1 == N];
            }
        }

        cout.flush();
    }
    return 0;
}