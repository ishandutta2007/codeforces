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

    int num_ids = divid.size();
    vector<vector<int>> furthest(k + 1, vector<int>(n));
    vector<int> seen(num_ids, 0);

    for (int chg = 0; chg <= k; chg++) {
        int i = 0, j = 0, repeat = 0;

        while (i < n) {
            while (j < n && (repeat < chg || seen[id[j]] == 0)) {
                seen[id[j]]++;
                repeat += seen[id[j]] > 1;
                j++;
            }
            furthest[chg][i] = j;
            seen[id[i]]--;
            repeat -= seen[id[i]] >= 1;
            i++;
        }
    }

    vector<vector<int>> dp(k + 1, vector<int>(n + 1, INT_MAX / 2));
    for (int chg = 0; chg <= k; chg++) {
        dp[chg][n] = 0;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int cur_chg = 0; cur_chg <= k; cur_chg++) {
            for (int suf_chg = 0; cur_chg + suf_chg <= k; suf_chg++) {
                int chg = cur_chg + suf_chg;
                dp[chg][i] = min(dp[chg][i], 1 + dp[suf_chg][furthest[cur_chg][i]]);
            }
        }
    }

    int best = INT_MAX;
    for (int chg = 0; chg <= k; chg++) {
        best = min(best, dp[chg][0]);
    }
    return best;
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