#include <bits/stdc++.h>

using namespace std;

#define long int64_t

// *****

auto factor_map(long n) {
    unordered_map<long, int> primes;
    for (long p = 2; p * p <= n; p++) {
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

auto get_divisors(const unordered_map<long, int>& factors, bool one, bool self) {
    vector<long> divs = {1};
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

long modfac(int n, long m) {
    long f = 1;
    while (n > 1) {
        f = (f * n--) % m;
    }
    return f;
}

long gcd(long a, long b, long& x, long& y) {
    long xn = 1, yn = 0;
    x = 0, y = 1;
    while (a != 0) {
        long q = b / a;
        b = b % a;
        x = x - q * xn, y = y - q * yn;
        swap(a, b), swap(x, xn), swap(y, yn);
    }
    if (b < 0) {
        b = -b, x = -x, y = -y;
    }
    return b;
}

long invmod(long a, long m) {
    long x, y, g = gcd(a, m, x, y);
    (void)g, assert(g == 1);
    x = x % m;
    return x >= 0 ? x : x + m;
}

long choosemod(long n, vector<int>& ks, long m) {
    assert(accumulate(begin(ks), end(ks), 0) == n);
    long x = modfac(n, m);
    for (int k : ks) {
        x = x * invmod(modfac(k, m), m) % m;
    }
    return x;
}

constexpr long mod = 998244353;

auto solve() {
    long N;
    cin >> N;
    auto factors = factor_map(N);
    int D = 1, P = 0; // num nodes | num primes
    for (const auto& [p, e] : factors) {
        D *= (e + 1), P += e;
    }
    cerr << "primes: " << P << endl;
    cerr << "nodes: " << D << endl;

    vector<long> divisor(D);
    vector<vector<int>> primes(D);
    unordered_map<long, int> where;
    divisor[0] = 1, primes[0].assign(P, 0), where[1] = 0;

    int K = 1, pi = 0;
    for (const auto& [p, e] : factors) {
        for (int n = 1; n <= e; n++) {
            for (int d = 0; d < K; d++) {
                int u = d + (n - 1) * K;
                int v = d + n * K;
                divisor[v] = divisor[u] * p;
                primes[v] = primes[u], primes[v][pi] = n;
                where.emplace(divisor[v], v);
            }
        }
        K *= e + 1, pi++;
    }

    int Q;
    cin >> Q;
    vector<int> ans(Q, 1);

    for (int q = 0; q < Q; q++) {
        long du, dv;
        cin >> du >> dv;
        long dg = gcd(du, dv);
        int u = where[du], v = where[dv], g = where[dg];
        vector<int> ksu(P), ksv(P);
        for (int i = 0; i < P; i++) {
            ksu[i] = primes[u][i] - primes[g][i];
            ksv[i] = primes[v][i] - primes[g][i];
        }
        int nu = accumulate(begin(ksu), end(ksu), 0);
        int nv = accumulate(begin(ksv), end(ksv), 0);
        long ug = choosemod(nu, ksu, mod);
        long vg = choosemod(nv, ksv, mod);
        cout << (ug * vg) % mod << endl;
    }
}

// *****

int main() {
    ios::sync_with_stdio(false);
    solve();
    return 0;
}