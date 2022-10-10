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
int MOD = 998244353;
const int LG = 30;

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

int dp[2 * LG][LG];

void solve() {
    int d, m;
    scanf("%d%d", &d, &m);

    memset(dp, 0, sizeof(dp));
    MOD = m;

    for (int i = 0; i < LG; ++i) {
        if ((1 << i) <= d) {
            dp[1][i] = (std::min((1ll << (i + 1)), (ll)d + 1) - (1ll << i)) % m;
        }
    }

    for (int len = 2; len < 2 * LG; ++len) {
        for (int last = 0; last < LG; ++last) {
            if ((1 << last) > d) {
                continue;
            }
            for (int prev = 0; prev < last; ++prev) {
                int cnt = (std::min((1ll << (last + 1)), (ll)d + 1) - (1ll << last)) % m;
                int cur = mul(dp[len - 1][prev], cnt, m);
                // if (cnt < 0) {
                //     std::cout << cur << '\n';
                // }
                dp[len][last] = add(dp[len][last], cur, m);
                // debug(cur);
            }
        }
    }

    int ans = 0;
    for (int len = 1; len < 2 * LG; ++len) {
        for (int last = 0; last < LG; ++last) {
            ans = add(ans, dp[len][last], m);
        }
    }

    printf("%d\n", ans);
}

void run() {
    int t;
    scanf("%d", &t);

    while (t--) {
        solve();
    }    
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