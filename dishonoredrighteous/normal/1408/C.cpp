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
const int N = 100100;

int a[N];

void solve() {
    int n, l;
    scanf("%d%d", &n, &l);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    int v1 = 1, v2 = 1;
    double pos1 = 0, pos2 = l;
    double ans = 0.0;

    int ptr1 = 0, ptr2 = n - 1;
    while (ptr1 <= ptr2) {
        if ((double)(a[ptr1] - pos1) / (double)v1 == (double)(pos2 - a[ptr2]) / (double)v2) {
            ans += (double)(a[ptr1] - pos1) / (double)v1;
            pos1 = a[ptr1];
            pos2 = a[ptr2];
            ++ptr1;
            --ptr2;
            ++v1;
            ++v2;
        } else if ((double)(a[ptr1] - pos1) / (double)v1 < (double)(pos2 - a[ptr2]) / (double)v2) {
            ans += (double)(a[ptr1] - pos1) / (double)v1;
            pos2 -= (double)(a[ptr1] - pos1) / (double)v1 * (double)v2;
            pos1 = a[ptr1];
            ++v1;
            ++ptr1;
        } else {
            ans += (double)(pos2 - a[ptr2]) / (double)v2;
            pos1 += (double)(pos2 - a[ptr2]) / (double)v2 * (double)v1;
            pos2 = a[ptr2];
            ++v2;
            --ptr2;
        }
    }

    if (pos1 <= pos2) {
        ans += (double)(pos2 - pos1) / (double)(v1 + v2);
    }

    printf("%.10lf\n", ans);
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