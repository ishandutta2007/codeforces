#include <bits/stdc++.h>

using namespace std;

#define long int64_t

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

namespace std {

template <typename T>
struct hash<vector<T>> : Hasher {};

} // namespace std

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

auto get_canonical(int n) {
    int canonical = 1;
    while (n > 1) {
        int p = lp[n];
        canonical *= p;
        do {
            n = nxt[n];
        } while (lp[n] == p);
    }
    return canonical;
}

auto get_factors(int n) {
    vector<int> factors;
    while (n > 1) {
        factors.push_back(lp[n]);
        n = nxt[n];
    }
    return factors;
}

inline void next_lexicographical_mask(unsigned& v) {
    unsigned c = v & -v, r = v + c;
    v = c ? (((r ^ v) >> 2) / c) | r : 0;
}

#define FOR_EACH_MASK(mask, size, max_size)                                            \
    for (unsigned mask = (1 << (size)) - 1, m##mask = 1 << (max_size); mask < m##mask; \
         next_lexicographical_mask(mask))

#define FOR_EACH_BIT_NUMBER(bit, n, mask)                                            \
    for (remove_const<decltype(mask)>::type z##bit = (mask), bit = z##bit & -z##bit, \
                                            n = __builtin_ctz(bit);                  \
         z##bit;                                                                     \
         z##bit ^= bit, z##bit && (bit = z##bit & -z##bit, n = __builtin_ctz(bit)))

int main() {
    ios::sync_with_stdio(false);
    constexpr int N = 1'000'000;
    least_prime_sieve(N);

    // # ints coprime with n up to x inclusive (inclusion exclusion)
    auto coprime_up_to = [&](int x, int, const vector<int>& factors) {
        assert(x >= 1);
        int D = factors.size();
        long bad = 0;
        for (int size = 1; size <= D; size++) {
            FOR_EACH_MASK (mask, size, D) {
                int v = 1;
                FOR_EACH_BIT_NUMBER (bit, i, mask) { v *= factors[i]; }
                if (size & 1) {
                    bad += x / v;
                } else {
                    bad -= x / v;
                }
            }
        }
        return x - bad;
    };

    unsigned T;
    cin >> T >> ws;
    while (T--) {
        int x, n, k;
        cin >> x >> n >> k;
        n = get_canonical(n);
        auto factors = get_factors(n);

        int minus = coprime_up_to(x, n, factors);

        int L = x, R = 50'000'000;
        while (L + 1 < R) {
            int M = (L + R) / 2;
            int upto = coprime_up_to(M, n, factors) - minus;
            if (upto >= k) {
                R = M;
            } else {
                L = M;
            }
        }
        cout << R << endl;
    }

    return 0;
}