#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

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
    int N, K;
    cin >> N >> K;
    vector<vector<int>> pos(K, vector<int>(N));
    for (int k = 0; k < K; k++) {
        for (int i = 0; i < N; i++) {
            cin >> pos[k][i];
        }
    }
    vector<int> sums(K);
    vector<long> sums2(K);
    for (int k = 0; k < K; k++) {
        for (int i = 0; i < N; i++) {
            sums[k] += pos[k][i];
            sums2[k] += 1LL * pos[k][i] * pos[k][i];
        }
    }

    // find when and delta
    vector<int> diffs(K - 1);
    set<int> diffcnt;
    for (int k = 0; k + 1 < K; k++) {
        diffs[k] = sums[k + 1] - sums[k];
        diffcnt.insert(diffs[k]);
    }
    assert(diffcnt.size() == 3u);
    debug(diffs, diffcnt);

    int loculp = *diffcnt.begin(), hiculp = *diffcnt.rbegin();
    int when = K - 1;
    int vdelta;
    for (int k = 0; k + 1 < K - 1; k++) {
        bool first = diffs[k] == loculp || diffs[k] == hiculp;
        bool second = diffs[k + 1] == loculp || diffs[k + 1] == hiculp;
        if (first && second) {
            when = k + 1;
            vdelta = (diffs[k] - diffs[k + 1]) / 2;
        }
    }
    debug(when, vdelta);

    // Editorial
    int a = when >= 3 ? 1 : when + 2;
    int vsum = *++diffcnt.begin();
    long v2sum = (sums2[a - 1] + sums2[a + 1] - 2 * sums2[a]) / 2;
    debug(vsum, v2sum);

    // Test every possibility
    for (int i = 0; i < N; i++) {
        // suppose culprit is pos[when][i]
        long x = pos[when][i];
        long new_v2sum = sums2[when] - x * x + (x - vdelta) * (x - vdelta);
        long new_v2 = (sums2[when - 1] + sums2[when + 1] - 2 * new_v2sum) / 2;
        debug(i, pos[when][i], new_v2);
        if (v2sum == new_v2) {
            cout << when << ' ' << x - vdelta << '\n';
            break;
        }
    }
    return 0;
}