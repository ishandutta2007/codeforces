// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <stdio.h>
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

template<typename T>
bool smin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool smax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const double PI = atan2(0.0, -1.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;
const int N = 5100;

ll a[N];
ll ans[N][N];
ll pref[N], minPref[N];

void solve() {
    int n, x;
    scanf("%d%d", &n, &x);

    for (int i = 0; i <= n; ++i) {
        for (int r = 0; r < n; ++r) {
            ans[i][r] = 0;
            pref[i] = 0;
            minPref[i] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
    }

    for (int i = 0; i < n; ++i) {
        pref[i] = a[i];
        if (i != 0) {
            pref[i] += pref[i - 1];
        }

        minPref[i] = pref[i];
        if (i != 0) {
            smin(minPref[i], minPref[i - 1]);
        }
        smin(minPref[i], 0ll);
    }

    // pref[r] - pref[r - 1] + x
    // pref[r] - pref[r - 2] + 2x
    // pref[r] - pref[r - 3] + 3x
    // ...
    // pref[r] - pref[r - k] + kx
    // pref[r] - pref[r - k - 1] + kx
    // ...
    // pref[r] - pref[0] + kx
    // pref[r] + kx

    for (int r = 0; r < n; ++r) {
        ans[0][r] = pref[r];
        if (r != 0) {
            ans[0][r] -= minPref[r - 1];
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int r = 0; r < n; ++r) {
            ans[k][r] = ans[k - 1][r];
            ll prev = 0;
            if (r - k >= 0) {
                smin(prev, minPref[r - k]);
            }

            if (r - k + 1 >= 0) {
                smax(ans[k][r], pref[r] - prev + 1ll * k * x);
            }
        }
    }

    for (int i = 0; i <= n; ++i) {
        ll cur = 0;
        for (int r = 0; r < n; ++r) {
            smax(cur, ans[i][r]);
        }
        printf("%lld ", cur);
    }
    printf("\n");
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