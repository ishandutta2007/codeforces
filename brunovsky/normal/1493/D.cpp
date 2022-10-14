#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

struct Hasher {
    template <typename U, typename V>
    size_t operator()(const pair<U, V>& p) const noexcept {
        using std::hash;
        size_t a = hash<U>{}(p.first), b = hash<V>{}(p.second);
        return (a + b) * (a + b + 1) / 2 + b;
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

constexpr long mod = 1e9 + 7;
int N, Q;
long g = 1;
vector<int> lp;
unordered_map<pair<int, int>, int, Hasher> cnt;
unordered_map<int, int> expo[200'000];

void add(int p, int e) {
    if (++cnt[{p, e}] == N) {
        g = g * p % mod;
    }
}

auto solve() {
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        while (n > 1) {
            int p = lp[n], e = 1, k = p;
            n /= p, add(p, e);
            while (lp[n] == p) {
                e++, n /= p, k *= p, add(p, e);
            }
            expo[i][p] = e;
        }
    }
    for (int q = 0; q < Q; q++) {
        int i, x;
        cin >> i >> x, i--;
        while (x > 1) {
            int p = lp[x], e = 1 + expo[i][p], k = p;
            x /= p, add(p, e);
            while (lp[x] == p) {
                e++, x /= p, k *= p, add(p, e);
            }
            expo[i][p] = e;
        }
        cout << g << endl;
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    lp = least_prime_sieve(200'001);
    solve();
    return 0;
}