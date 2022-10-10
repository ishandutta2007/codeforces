// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#ifdef PERVEEVM_LOCAL
    #define debug(x) std::cerr << (#x) << ":\t" << (x) << std::endl
#else
    #define debug(x) 238;
#endif

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0)
#define NAME "File"

using ll = long long;
using ld = long double;

#ifdef PERVEEVM_LOCAL
    std::mt19937 rnd(238);
#else
    std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

const double PI = atan2(0.0, -1.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;
const int N = 5100;
const int MOD = (int)1e9 + 7;

int add(int a, int b, int mod = MOD) {
    if (a + b >= mod) {
        return a + b - mod;
    }
    return a + b;
}

int sub(int a, int b, int mod = MOD) {
    if (a - b < 0) {
        return a - b + mod;
    }
    return a - b;
}

int mul(int a, int b, int mod = MOD) {
    return (int)(1ll * a * b % mod);
}

int binpow(int a, int n, int mod = MOD) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        return binpow(mul(a, a, mod), n / 2, mod);
    } else {
        return mul(binpow(a, n - 1, mod), a, mod);
    }
}

int rev(int a, int mod = MOD) {
    return binpow(a, mod - 2, mod);
}

int c[N][N];

void precalc() {
    c[1][1] = 1;

    for (int k = 1; k < N - 1; ++k) {
        for (int i = 1; i <= k; ++i) {
            c[k + 1][i] = add(c[k + 1][i], mul(c[k][i], i));
            if (i + 1 < N) {
                c[k + 1][i + 1] = add(c[k + 1][i + 1], c[k][i]);
            }
        }
    }
}

void run() {
    int n, k;
    scanf("%d%d", &n, &k);

    precalc();

    int cur = 1;
    int ans = 0;
    for (int i = n; i >= std::max(1, n - k + 1); --i) {
        cur = mul(cur, i);
        ans = add(ans, mul(mul(cur, c[k][n - i + 1]), binpow(2, i)));
    }

    ans = mul(ans, rev(2));

    printf("%d\n", ans);
}

int main(void) {
    // freopen(NAME".in", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    auto start = std::chrono::high_resolution_clock::now();
    run();
    auto end = std::chrono::high_resolution_clock::now();

    #ifdef PERVEEVM_LOCAL
        std::cerr << "Execution time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
    #endif

    return 0;
}