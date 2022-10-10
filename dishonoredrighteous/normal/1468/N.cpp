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

void solve() {
    int c1, c2, c3;
    int a1, a2, a3, a4, a5;
    scanf("%d%d%d%d%d%d%d%d", &c1, &c2, &c3, &a1, &a2, &a3, &a4, &a5);

    if (c1 < a1 || c2 < a2 || c3 < a3) {
        printf("NO\n");
        return;
    }

    c1 -= a1;
    c2 -= a2;
    c3 -= a3;

    if (c1 >= a4) {
        c1 -= a4;
    } else {
        a4 -= c1;
        c3 -= a4;
    }

    if (c2 >= a5) {
        c2 -= a5;
    } else {
        a5 -= c2;
        c3 -= a5;
    }

    if (c3 >= 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
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