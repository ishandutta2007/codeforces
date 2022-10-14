#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto sum_divisors_sieve(int N) {
    vector<long> sum_divisors(N + 1, 1);
    sum_divisors[0] = 0;

    for (int n = 2; n <= N; n++) {
        if (sum_divisors[n] == 1) {
            for (long m = n, k = 1 + n; m <= N; m *= n, k += m) {
                for (int i = 1; i * m <= N; i++) {
                    for (int b = 1; b < n && i * m <= N; i++, b++) {
                        sum_divisors[i * m] *= k;
                    }
                }
            }
        }
    }

    return sum_divisors;
}

constexpr int maxn = 10'000'000;
vector<long> sumdiv;
vector<int> first;

void setup() {
    sumdiv = sum_divisors_sieve(maxn);
    first.assign(maxn + 1, -1);
    for (int n = 1; n <= maxn; n++) {
        if (sumdiv[n] <= maxn && first[sumdiv[n]] == -1) {
            first[sumdiv[n]] = n;
        }
    }
}

auto solve() {
    int S;
    cin >> S;
    assert(1 <= S && S <= maxn);
    cout << first[S] << endl;
}

// *****

int main() {
    ios::sync_with_stdio(false);
    setup();
    unsigned T;
    cin >> T >> ws;
    for (unsigned t = 1; t <= T; ++t) {
        solve();
    }
    return 0;
}