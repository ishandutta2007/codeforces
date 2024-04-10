#include <bits/stdc++.h>

using namespace std;

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
    template <typename U, typename V>
    size_t operator()(const pair<U, V>& p) const noexcept {
        using std::hash;
        size_t a = hash<U>{}(p.first), b = hash<V>{}(p.second);
        return (a + b) * (a + b + 1) / 2 + b;
    }
    template <typename U>
    size_t operator()(const array<U, 2>& p) const noexcept {
        using std::hash;
        hash<U> hasher;
        size_t a = hasher(p[0]), b = hasher(p[1]);
        return (a + b) * (a + b + 1) / 2 + b;
    }
    template <int i, typename Tuple>
    size_t tuple_compute(const Tuple& tuple) const noexcept {
        if constexpr (i == std::tuple_size_v<Tuple>) {
            return std::tuple_size_v<Tuple>;
        } else {
            using std::hash;
            hash<std::tuple_element_t<i, Tuple>> hasher;
            size_t seed = tuple_compute<i + 1, Tuple>(tuple);
            size_t h = hasher(std::get<i>(tuple));
            return seed ^ (h + 0x9e3779b9 + (seed << 6) + (seed >> 2));
        }
    }
    template <typename... Ts>
    size_t operator()(const tuple<Ts...>& t) const noexcept {
        return tuple_compute<0, tuple<Ts...>>(t);
    }
};

auto least_prime_sieve(int N) {
    vector<int> primes, lp(N + 1, 0);

    for (int P = 0, n = 2; n <= N; n++) {
        if (lp[n] == 0) {
            lp[n] = n, primes.push_back(n), P++;
        }
        for (int i = 0; i < P && primes[i] <= lp[n] && n * primes[i] <= N; ++i) {
            lp[n * primes[i]] = primes[i];
        }
    }

    return lp;
}

vector<int> lp;

auto solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    unordered_map<vector<int>, int, Hasher> divid;
    vector<int> id(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        int a = A[i], p;
        vector<int> primes;
        while (a > 1) {
            p = lp[a], a /= p;
            if (!primes.empty() && primes.back() == p) {
                primes.pop_back();
            } else {
                primes.push_back(p);
            }
        }
        id[i] = divid.emplace(primes, divid.size()).first->second;
    }
    int intervals = 0, i = 0;
    while (i < n) {
        unordered_map<int, int> seen;
        int repeated = 0;
        int j = i + 1;
        seen[id[i]] = 1;
        while (j < n && (repeated < k || !seen.count(id[j])))
            seen[id[j]]++, repeated += seen[id[j]] > 1, j++;
        intervals++, i = j;
    }
    return intervals;
}

// *****

int main() {
    lp = least_prime_sieve(10'000'000);
    ios::sync_with_stdio(false);
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        cout << solve() << endl;
    }
    return 0;
}