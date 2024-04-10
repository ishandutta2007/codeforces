#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

using namespace std;

// Compute phi(n) of all n<=N. O(N log log N)
auto phi_sieve(int N) {
    vector<int> phi;
    phi.resize(N + 1);
    iota(begin(phi), end(phi), 0);

    for (int i = 1; i <= N; i++) {
        for (int j = 2 * i; j <= N; j += i) {
            phi[j] -= phi[i];
        }
    }
    return phi;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n;
    cin >> n;
    auto phi = phi_sieve(n);

    int64_t ans = 0;
    for (int g = 1; 1 + 2 * g <= n; g++) {
        int d = n % g;
        for (int c = d; c + 2 * g <= n; c += g) {
            int m = (n - c) / g;
            ans += 1LL * lcm(c, g) * phi[m];
        }
    }
    cout << ans % 1'000'000'007 << '\n';
    return 0;
}

// Probably iterate over g=gcd(a,b)
// must pick a=Ag and b=Bg and gcd(A,B)=1
// So contribution is SUM lcm(c,g) where A+B=m=(n-c)/g and A,B are coprime
// But now you iterate c and compute m
// As long as A is coprime with m you're good