#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

static constexpr int M = 1'000'000;

// Compute least prime divisors and n/lp[n] of all n<=N. O(N)
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

auto get_factors(int n) {
    map<int, int> primes;
    while (n > 1) {
        int p = lp[n], k = 0;
        do {
            n = nxt[n], k++;
        } while (n > 1 && lp[n] == p);
        primes[p] = k;
    }
    return primes;
}

int64_t intpow(int64_t b, int64_t e) {
    int64_t power = 1;
    while (e > 0) {
        if (e & 1) {
            power = power * b;
        }
        e >>= 1;
        b = b * b;
    }
    return power;
}

int64_t intfac(int n) {
    int64_t f = 1;
    while (n > 1) {
        f = f * n--;
    }
    return f;
}

int64_t choose(int n, int k) {
    return n < 0 || k < 0 || k > n ? 0 : intfac(n) / (intfac(n - k) * intfac(k));
}

auto count_powers(const vector<int>& a) {
    vector<vector<pair<int, int>>> powers(M + 1);
    for (int x : a) {
        for (auto [p, c] : get_factors(x)) {
            powers[p].push_back({c, x});
        }
    }
    for (int p : primes) {
        if (int N = a.size(), S = powers[p].size(); S == N - 1) {
            for (int x : a) {
                if (x % p != 0) {
                    powers[p].push_back({0, x});
                }
            }
        }
    }
    return powers;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    least_prime_sieve(M);
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<vector<int>> pos(M + 1);
    for (int i = 0; i < N; i++) {
        pos[a[i]].push_back(i + 1);
    }
    auto get_index = [&](int v) {
        if (pos[v].empty()) {
            return -1;
        } else {
            int i = pos[v].back();
            pos[v].pop_back();
            return i;
        }
    };
    if (count(begin(a), end(a), a[0]) == N) {
        if (N == 1) {
            cout << "1\n0 1 1\n";
        } else {
            cout << "2\n0 1 1\n0 1 1\n";
        }
        return 0;
    }
    sort(begin(a), end(a));
    set<int> uniqs(begin(a), end(a));
    auto apow = count_powers(a);
    vector<int> cands;
    for (int p : primes) {
        if (int S = apow[p].size(); S == N) { // N>=2
            nth_element(begin(apow[p]), begin(apow[p]) + 2, end(apow[p]));
            auto [a0, x0] = apow[p][0];
            auto [a1, x1] = apow[p][1];
            cands.push_back(x0);
            cands.push_back(x1);
        }
    }
    vector<int> index, xs;
    for (int x : cands) {
        if (int i = get_index(x); i != -1) {
            index.push_back(i);
            xs.push_back(x);
        }
    }
    while (true) {
        int X = xs.size(); // <=14 works, >15 fails
        auto xpow = count_powers(xs);
        for (int p : primes) {
            int XS = xpow[p].size();
            int AS = apow[p].size();
            if (AS < N && XS == X) {
                for (int x : uniqs) {
                    if (x % p) {
                        if (int i = get_index(x); i != -1) {
                            index.push_back(i);
                            xs.push_back(x);
                            goto step;
                        }
                    }
                }
            }
        }
        break;
    step:
        continue;
    }

    int X = xs.size();
    vector<int64_t> uses(X + 1), query(X + 1);
    auto insert = [&](int v, int c) {
        query[v] += c;
        for (int i = v; i <= X; i++) {
            uses[i] += c * choose(i - 1, v - 1);
        }
    };
    insert(1, 1);
    for (int v = 3; v <= X; v++) {
        insert(v, -uses[v]);
    }
    int Q = 0, C = 0;
    for (int v = 1; v <= X; v++) {
        C += abs(query[v]) * choose(X, v);
        Q += abs(query[v]) * v * choose(X, v);
    }
    assert(Q <= 1e6 && C <= 1e5);
    debug(X, xs);
    debug(Q, C, uses, query);
    vector<vector<vector<int>>> pts(X + 1);
    for (int m = 0; m < (1 << X); m++) {
        vector<int> indices;
        for (int i = 0; i < X; i++) {
            if (m >> i & 1) {
                indices.push_back(index[i]);
            }
        }
        sort(begin(indices), end(indices));
        pts[__builtin_popcount(m)].push_back(move(indices));
    }
    cout << C << '\n';
    for (int v = 1; v <= X; v++) {
        while (query[v] > 0) {
            for (const auto& indices : pts[v]) {
                cout << 0 << ' ' << v;
                for (int x : indices) {
                    cout << ' ' << x;
                }
                cout << '\n';
            }
            query[v]--;
        }
        while (query[v] < 0) {
            for (const auto& indices : pts[v]) {
                cout << 1 << ' ' << v;
                for (int x : indices) {
                    cout << ' ' << x;
                }
                cout << '\n';
            }
            query[v]++;
        }
    }
    // too many xs now...
    return 0;
}