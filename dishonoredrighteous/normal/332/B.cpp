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
const int N = 200100;

int a[N];
ll sum[N], maxSum[N];
int maxSumId[N];

void run() {
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        // std::cout << a[i] << ' ';
    }
    // std::cout << '\n';

    for (int i = 0; i < n; ++i) {
        sum[i] += a[i];
        if (i != 0) {
            sum[i] += sum[i - 1];
        }
        if (i - k >= 0) {
            sum[i] -= a[i - k];
        }

        maxSum[i] = sum[i];
        maxSumId[i] = i;
        if (i != 0) {
            if (smax(maxSum[i], maxSum[i - 1]) || maxSum[i - 1] == maxSum[i]) {
                maxSumId[i] = maxSumId[i - 1];
            }
        }
    }

    // for (int i = 0; i < n; ++i) {
    //     std::cout << sum[i] << ' ';
    // }
    // std::cout << '\n';

    ll ans = 0;
    int bestI = -1, bestJ = -1;
    for (int i = 2 * k - 1; i < n; ++i) {
        if (smax(ans, sum[i] + maxSum[i - k])) {
            bestI = maxSumId[i - k] - k + 1;
            bestJ = i - k + 1;
        }
        // std::cout << sum[i] + maxSum[i - k] << '\n';
    }

    // printf("%lld\n", ans);
    printf("%d %d\n", bestI + 1, bestJ + 1);
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