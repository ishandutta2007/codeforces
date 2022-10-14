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
            lp[n] = n, P++, primes.push_back(n);
        }
        for (int i = 0; i < P && primes[i] <= lp[n] && n * primes[i] <= N; ++i) {
            lp[n * primes[i]] = primes[i], nxt[n * primes[i]] = n;
        }
    }

    return lp;
}

auto output(int N, vector<int> bad) {
    vector<int> ok(N + 1, true);
    for (int n : bad) {
        ok[n] = false;
    }
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        if (ok[i]) {
            ans.push_back(i);
        }
    }
    int A = ans.size();
    cout << A << '\n';
    for (int i = 0; i < A; i++) {
        cout << ans[i] << " \n"[i + 1 == A];
    }
    exit(0);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;

    // Generate a mask for each prime
    least_prime_sieve(N);

    static mt19937 mt(random_device{}());
    static uniform_int_distribution<uint64_t> maskd(0, UINT64_MAX);

    vector<uint64_t> prime_mask(N + 1);
    for (int i = 1; i <= N; i++) {
        if (lp[i] == i) {
            prime_mask[i] = maskd(mt);
        }
    }

    vector<uint64_t> fac_mask(N + 1);
    fac_mask[1] = 0;
    for (int n = 2; n <= N; n++) {
        fac_mask[n] = fac_mask[n - 1];
        int k = n;
        while (k > 1) {
            fac_mask[n] ^= prime_mask[lp[k]];
            k = nxt[k];
        }
    }

    map<uint64_t, vector<int>> which;

    uint64_t all_mask = 0;
    for (int n = 1; n <= N; n++) {
        all_mask ^= fac_mask[n];
        which[fac_mask[n]].push_back(n);
    }

    while (true) {
        if (all_mask == 0) {
            output(N, {});
        }
        if (which.count(all_mask)) {
            output(N, {which.at(all_mask).back()});
        }
        for (int k = N; k >= 1; k--) {
            if (which.count(all_mask ^ fac_mask[k])) {
                output(N, {which.at(all_mask ^ fac_mask[k]).back(), k});
            }
        }
        which[fac_mask[N]].pop_back();
        all_mask ^= fac_mask[N--];
    }

    return 0;
}

// For each prime you have some list of integers with odd factorial exponent
// These lists consist of many runs of integers, e.g. p!,(p+1)!,...,(2p-1)!
// For most primes this doesn't even get to (p^2)! so you get less than p runs actually
// Your subset projected on these runs must have even size for every prime p
// We can greedily pick integers which don't appear in any subset but thats just 1!