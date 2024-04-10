#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

vector<int> primes;
vector<bool> isprime;

auto classic_sieve(int N) {
    isprime.assign(N + 1, true);

    for (int n = 4; n <= N; n += 2)
        isprime[n] = false;
    for (int n = 3; n * n <= N; n += 2)
        if (isprime[n])
            for (int i = n * n; i <= N; i += 2 * n)
                isprime[i] = false;
    if (N > 2)
        primes.push_back(2);
    for (int n = 3; n <= N; n += 2)
        if (isprime[n])
            primes.push_back(n);

    return primes;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    classic_sieve(100'000);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cout << primes[i] << " \n"[i + 1 == N];
        }
    }
    return 0;
}