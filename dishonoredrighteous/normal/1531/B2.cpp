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

void run() {
    int n;
    scanf("%d", &n);

    std::map<int, int> cntW, cntH;
    std::map<std::pair<int, int>, int> cnt;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int w, h;
        scanf("%d%d", &w, &h);

        if (w == h) {
            ans += cntW[w];
            ans += cntH[w];
            ans -= cnt[std::make_pair(w, w)];
        } else {
            ll cur = cntW[w] + cntW[h] + cntH[w] + cntH[h];
            cur -= cnt[std::make_pair(w, h)];
            cur -= cnt[std::make_pair(h, w)];
            cur -= cnt[std::make_pair(w, w)];
            cur -= cnt[std::make_pair(h, h)];
            ans += cur;
        }

        ++cntW[w];
        ++cntH[h];
        ++cnt[std::make_pair(w, h)];
        
        // std::cout << ans << std::endl;
    }

    printf("%lld\n", ans);
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