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
ll pref[N];

void run() {
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    std::sort(a, a + n);

    for (int i = 0; i < n; ++i) {
        pref[i] = a[i];
        if (i != 0) {
            pref[i] += pref[i - 1];
        }
    }

    ll ans = LINF;
    for (int i = 0; i < n; ++i) {
        int l = i, r = i;
        while (r + 1 < n && a[r + 1] == a[l]) {
            ++r;
        }

        int cur = a[l];
        int need = k - (r - l + 1);

        if (need <= 0) {
            printf("0\n");
            return;
        }

        int leftCnt = l;
        int rightCnt = n - r - 1;

        ll leftCost = 1ll * leftCnt * cur;
        if (l != 0) {
            leftCost -= pref[l - 1];
        }

        ll rightCost = (pref[n - 1] - pref[r]) - 1ll * rightCnt * cur;

        if (leftCnt >= need) {
            ans = std::min(ans, leftCost - (leftCnt - need));
        }
        if (rightCnt >= need) {
            ans = std::min(ans, rightCost - (rightCnt - need));
        }

        ans = std::min(ans, leftCost + rightCost - (leftCnt + rightCnt - need));

        i = r;
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