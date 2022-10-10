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
const int N = 200100;

int a[N];
ll s0[N], s1[N];
ll delta[N];

void solve() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        s0[i] = 0;
        s1[i] = 0;
        delta[i] = 0;
    }

    ll ans = 0;
    for (int i = 0; i < n; i += 2) {
        ans += a[i];
    }

    ll sum = ans;

    // debug(ans);

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            s0[i] = a[i];
        } else {
            s1[i] = a[i];
        }

        if (i > 0) {
            s0[i] += s0[i - 1];
            s1[i] += s1[i - 1];
        }
    }

    for (int i = 0; i < n; ++i) {
        delta[i] = s1[i] - s0[i];
    }

    ll min0 = LINF, min1 = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            ans = std::max(ans, sum + delta[i] - min0);
            min0 = std::min(min0, delta[i]);
        } else {
            ans = std::max(ans, sum + delta[i] - min1);
            min1 = std::min(min1, delta[i]);
        }
    }

    printf("%lld\n", ans);
}

void run() {
    int t = 1;
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