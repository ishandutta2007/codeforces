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

    return lp;
}

auto get_primes(int n) {
    vector<int> ps;
    while (n > 1) {
        int p = lp[n];
        ps.push_back(p);
        do {
            n = nxt[n];
        } while (n > 1 && lp[n] == p);
    }
    return ps;
}

template <typename Fun>
class y_combinator_result {
    Fun fun_;

  public:
    template <typename T>
    explicit y_combinator_result(T&& fun) : fun_(std::forward<T>(fun)) {}

    template <typename... Args>
    decltype(auto) operator()(Args&&... args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template <typename Fun>
auto y_combinator(Fun&& fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

int64_t choose(int64_t n) { return n * (n - 1) / 2; }

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    const int M = 500'000;
    least_prime_sieve(M);
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<int8_t> in(N);
    vector<int> cnt(M + 1);
    int64_t nonzero = 0, total = 0;

    // keep track of pairs where gcd(i,j)>1

    auto operate = [&](int n, int b) {
        auto ps = get_primes(n);
        int S = ps.size();
        y_combinator([&](auto self, int i, int v, int s) -> void {
            if (i < S) {
                self(i + 1, v, s);
                self(i + 1, v * ps[i], s ^ 1);
            } else if (v > 1) {
                int c = cnt[v];
                int d = cnt[v] = cnt[v] + b;
                nonzero -= s == 1 ? choose(c) : -choose(c);
                nonzero += s == 1 ? choose(d) : -choose(d);
            }
        })(0, 1, 0);
    };
    auto insert = [&](int n) { return operate(n, +1); };
    auto remove = [&](int n) { return operate(n, -1); };

    while (Q--) {
        int x;
        cin >> x, x--;
        total += in[x] ? -1 : +1;
        in[x] ? remove(a[x]) : insert(a[x]);
        in[x] = !in[x];
        cout << choose(total) - nonzero << '\n';
    }
    return 0;
}