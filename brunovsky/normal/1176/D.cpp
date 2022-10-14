#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

vector<int> primes, lp, nxt;
unordered_map<int, int> prime_index;

auto least_prime_sieve(int N) {
    lp.assign(N + 1, 0), nxt.assign(N + 1, 0);

    for (int P = primes.size(), n = 2; n <= N; n++) {
        if (lp[n] == 0) {
            lp[n] = n, nxt[n] = 1;
        }
        for (int i = 0; i < P && primes[i] <= lp[n] && n * primes[i] <= N; ++i) {
            lp[n * primes[i]] = primes[i], nxt[n * primes[i]] = n;
        }
    }
}

auto classic_sieve(int N) {
    vector<bool> isprime;
    isprime.assign(N + 1, true);

    for (int n = 4; n <= N; n += 2)
        isprime[n] = false;
    for (int n = 3; n * n <= N; n += 2)
        if (isprime[n])
            for (int i = n * n; i <= N; i += 2 * n)
                isprime[i] = false;
    if (N > 2)
        primes.push_back(2), prime_index[2] = 1;
    for (int n = 3, P = 1; n <= N; n += 2) {
        if (isprime[n]) {
            prime_index.emplace(n, ++P);
            primes.push_back(n);
        }
    }

    return primes;
}

auto solve() {
    int N;
    cin >> N;
    vector<int> a;
    vector<int> small(200'001, 0);
    for (int i = 0; i < 2 * N; i++) {
        int num;
        cin >> num;
        if (num > 200'000) {
            a.push_back(prime_index[num]);
            small[prime_index[num]]--;
        } else {
            small[num]++;
        }
    }
    for (int n = 200'000; n >= 2; n--) {
        while (small[n]) {
            small[n]--;
            if (nxt[n] != 1) {
                // composite
                int m = nxt[n];
                small[m]--;
                a.push_back(n);
            } else {
                // prime
                int m = prime_index[n];
                small[m]--;
                a.push_back(m);
            }
        }
    }
    assert(int(a.size()) == N);
    for (int i = 0; i < N; i++) {
        cout << (i ? " " : "") << a[i];
    }
    cout << endl;
}

// *****

int main() {
    setbuf(stdout, nullptr);
    ios::sync_with_stdio(false);
    classic_sieve(2'750'159);
    least_prime_sieve(200'000);
    solve();
    return 0;
}