#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

vector<int> primes, lp, nxt;

auto least_prime_sieve(int N) {
    lp.assign(N + 1, 0), nxt.assign(N + 1, 0);

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

template <typename T>
string to_string(const vector<T>& v) {
    string s;
    for (const auto& el : v)
        s += to_string(el) + " ";
    return s.empty() ? s : (s.pop_back(), s);
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    return out << to_string(v);
}

auto solve() {
    int N;
    cin >> N;
    least_prime_sieve(N);
    vector<int> ans(N + 1, 1);
    vector<bool> included(N + 1, false);
    int P = primes.size();
    included[1] = true;
    for (int n = 1; n <= P; n++) {
        ans[n] = 1, included[primes[n - 1]] = true;
    }

    int g = 1, curr = P + 1, p = 0;

    while (curr < N) {
        // allow g -> g+1
        int prev = curr;
        g++, curr += !included[g], included[g] = true;
        for (int i = 0; i < P && primes[i] <= g && primes[i] * g <= N; i++) {
            int n = primes[i] * g;
            if (nxt[n] <= g) {
                curr += !included[n], included[n] = true;
            }
        }
        p++;
        for (int n = prev + 1; n <= curr; n++) {
            ans[n] = g;
        }
    }

    for (int n = 2; n <= N; n++) {
        cout << (n > 2 ? " " : "") << ans[n];
    }
    cout << endl;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}