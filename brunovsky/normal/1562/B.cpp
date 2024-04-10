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

    isprime[1] = false;
    return primes;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    classic_sieve(100'000);
    int T;
    cin >> T;
    while (T--) {
        // 1000 composites, try them all
        int k;
        string n;
        cin >> k >> n;

        int x = 0;
        while (true) {
            if (isprime[++x]) {
                continue;
            }
            string z = to_string(x);
            int zi = 0, Z = z.size();
            for (int i = 0; i < k && zi < Z; i++) {
                if (n[i] == z[zi]) {
                    zi++;
                }
            }
            if (zi == Z) {
                cout << Z << '\n';
                cout << z << '\n';
                break;
            }
        }
    }
    return 0;
}