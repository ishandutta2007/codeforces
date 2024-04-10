#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

struct disjoint_set {
    int N, S;
    vector<int> next, size;

    explicit disjoint_set(int N = 0) : N(N), S(N), next(N), size(N, 1) {
        iota(begin(next), end(next), 0);
    }

    void assign(int N) { *this = disjoint_set(N); }
    bool same(int i, int j) { return find(i) == find(j); }
    bool unit(int i) { return i == next[i] && size[i] == 1; }
    bool root(int i) { return find(i) == i; }
    void reroot(int u) {
        if (u != find(u)) {
            size[u] = size[find(u)];
            next[u] = next[find(u)] = u;
        }
    }

    int find(int i) {
        while (i != next[i]) {
            i = next[i] = next[next[i]];
        }
        return i;
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (size[i] < size[j]) {
                swap(i, j);
            }
            next[j] = i;
            size[i] += size[j];
            S--;
            return true;
        }
        return false;
    }
};

int MAX = 2'000'000, P;
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

    P = primes.size();
}

auto get_primes(int n) {
    vector<int> primes;
    while (n > 1) {
        int p = lp[n];
        primes.push_back(p);
        do {
            n = nxt[n];
        } while (lp[n] == p);
    }
    return primes;
}

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

namespace std {

template <typename T, size_t N>
struct hash<array<T, N>> : Hasher {};
template <typename T>
struct hash<vector<T>> : Hasher {};
template <typename U, typename V>
struct hash<pair<U, V>> : Hasher {};
template <typename... Ts>
struct hash<tuple<Ts...>> : Hasher {};

} // namespace std

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    least_prime_sieve(MAX);

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> prime_index(MAX + 1);
    for (int i = 0; i < P; i++) {
        prime_index[primes[i]] = i;
    }

    // the answer is at most 2
    vector<vector<int>> factors(N);
    for (int i = 0; i < N; i++) {
        factors[i] = get_primes(arr[i]);
    }

    disjoint_set dsu(N + P);
    for (int i = 0; i < N; i++) {
        for (int p : factors[i]) {
            dsu.join(prime_index[p], i + P);
        }
    }

    vector<pair<int, int>> queries(Q);
    vector<int> ans(Q, 2);
    for (int i = 0; i < Q; i++) {
        auto& [s, t] = queries[i];
        cin >> s >> t, s--, t--;
        if (dsu.same(s + P, t + P)) {
            ans[i] = 0;
        }
    }

    unordered_map<pair<int, int>, set<int>> querymap;
    for (int i = 0; i < Q; i++) {
        auto [s, t] = queries[i];
        if (ans[i] != 0) {
            for (int p : factors[s]) {
                for (int q : factors[t]) {
                    int u = dsu.find(prime_index[p]);
                    int v = dsu.find(prime_index[q]);
                    assert(u != v && p != q);
                    querymap[minmax(u, v)].insert(i);
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        // consider arr[i]*(arr[i]+1)
        auto fs = get_primes(arr[i] + 1);
        for (int p : factors[i]) {
            for (int q : fs) {
                int u = dsu.find(prime_index[p]);
                int v = dsu.find(prime_index[q]);
                assert(p != q);
                if (u != v && querymap.count(minmax(u, v))) {
                    for (int j : querymap.at(minmax(u, v))) {
                        ans[j] = 1;
                    }
                    querymap.erase(minmax(u, v));
                }
            }
        }
        for (int p : fs) {
            for (int q : fs) {
                int u = dsu.find(prime_index[p]);
                int v = dsu.find(prime_index[q]);
                if (u != v && querymap.count(minmax(u, v))) {
                    for (int j : querymap.at(minmax(u, v))) {
                        ans[j] = 1;
                    }
                    querymap.erase(minmax(u, v));
                }
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}