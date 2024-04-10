#include <bits/stdc++.h>
using namespace std;
#define long int64_t
static_assert(sizeof(int) == 4 && sizeof(long) == 8);

template <typename T>
auto factor_map(T n) {
    unordered_map<T, int> primes;
    for (T p = 2; p * p <= n; p++) {
        while (n % p == 0) {
            primes[p]++;
            n = n / p;
        }
    }
    if (n > 1) {
        primes[n]++;
    }
    return primes;
}

template <typename T>
auto get_divisors(const unordered_map<T, int>& factors, bool one, bool self) {
    vector<T> divs = {1};
    for (const auto& [p, e] : factors) {
        int D = divs.size();
        divs.resize(D * (e + 1));
        for (int n = 1; n <= e; n++) {
            for (int d = 0; d < D; d++) {
                divs[d + n * D] = divs[d + (n - 1) * D] * p;
            }
        }
    }
    if (!one) {
        divs.erase(begin(divs));
    }
    if (!self && !divs.empty()) {
        divs.erase(begin(divs) + (divs.size() - 1));
    }
    return divs;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        bool power_two = (N & (N - 1)) == 0;
        int e = __builtin_ctz(N);
        if (N == 1) {
            cout << "Bob\n";
        } else if (power_two && e % 2 == 1) {
            cout << "Bob\n";
        } else if (power_two && e % 2 == 0) {
            cout << "Alice\n";
        } else if (N % 2 == 0) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
    return 0;
}