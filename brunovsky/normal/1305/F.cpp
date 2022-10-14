#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

int64_t distance(int64_t n, int64_t p) {
    if (n <= p) {
        return p - n;
    } else {
        int64_t k = n % p;
        return min(k, p - k);
    }
}

int TOP = 1'000'000;
vector<int> primes;

auto classic_sieve(int N) {
    vector<bool> isprime;
    isprime.assign(N + 1, true);

    for (int n = 4; n <= N; n += 2)
        isprime[n] = false;
    for (int n = 3; n * n <= N; n += 2)
        if (isprime[n])
            for (int i = n * n; i <= N; i += 2 * n)
                isprime[i] = false;
    for (int n = 2; n <= N; n++)
        if (isprime[n])
            primes.push_back(n);

    return primes;
}

auto get_range_prime_divisors(int64_t L, int64_t R, const vector<int>& primes) {
    assert(1 <= L && L <= R);
    int N = R - L + 1;
    vector<int64_t> a(N);
    vector<int64_t> found;
    iota(begin(a), end(a), L);
    for (int p : primes) {
        int r = L % p, d = r == 0 ? 0 : p - r;
        if (d < N) {
            found.push_back(p);
        }
        for (int i = d; i < N; i += p) {
            do {
                a[i] /= p;
            } while (a[i] % p == 0);
        }
    }
    int F = found.size();
    for (int64_t n : a) {
        if (n > 1) {
            found.push_back(n);
        }
    }
    sort(begin(found) + F, end(found));
    return found;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    classic_sieve(TOP);

    vector<int64_t> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    mt19937 mt(random_device{}());
    uniform_int_distribution<int> indexd(0, N - 1);

    int64_t M = a[indexd(mt)];
    int64_t L = max<int64_t>(2, M - N), R = M + N;

    vector<int64_t> cands = get_range_prime_divisors(L, R, primes);

    int64_t ans = 0;
    for (int i = 0; i < N; i++) {
        ans += a[i] % 2;
    }

    shuffle(begin(a), end(a), mt);
    shuffle(begin(cands), end(cands), mt);

    for (int64_t p : cands) {
        int64_t here = 0;
        for (int i = 0; i < N && here < ans; i++) {
            here += distance(a[i], p);
        }
        ans = min(ans, here);
    }
    cout << ans << '\n';
    return 0;
}