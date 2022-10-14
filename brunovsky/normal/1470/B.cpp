#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

struct Hasher {
    template <typename Container>
    size_t operator()(const Container& vec) const noexcept {
        using std::hash;
        hash<typename Container::value_type> hasher;
        size_t seed = distance(begin(vec), end(vec));
        for (const auto& n : vec) {
            seed ^= hasher(n) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

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

auto get_evens(int n) {
    unordered_set<int> evens;
    while (n > 1) {
        evens.count(lp[n]) ? (void)evens.erase(lp[n]) : (void)evens.insert(lp[n]);
        n = nxt[n];
    }
    vector<int> v(begin(evens), end(evens));
    sort(begin(v), end(v));
    return v;
}

int N, Q, M;
int A[300'000];
int idcnt[300'000];
unordered_map<vector<int>, int, Hasher> idmap;

auto solve() {
    cin >> N;
    memset(idcnt, 0, N * sizeof(int));
    idmap.clear();
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        auto evens = get_evens(A[i]);
        int id = idmap.emplace(evens, idmap.size()).first->second;
        idcnt[id]++;
    }
    M = idmap.size();
    int zeroid = idmap.count({}) ? idmap.at({}) : -1;
    int ans0 = *max_element(idcnt, idcnt + M); // answer to query 0, max of idcnt
    int ans1 = 0;                              // answer to query 1
    int sum0 = 0;
    for (int id = 0; id < M; id++) {
        if (id != zeroid && idcnt[id] % 2 == 1) {
            ans1 = max(ans1, idcnt[id]);
        } else {
            sum0 += idcnt[id];
        }
    }
    ans1 = max(ans1, sum0);
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        long w;
        cin >> w;
        cout << (w ? ans1 : ans0) << endl;
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    least_prime_sieve(1'000'000);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        solve();
    }
    return 0;
}