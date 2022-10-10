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
const int N = 110;

int a[N], b[N];
int dp[2][N][N * N];

void init(int layer) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N * N; ++j) {
            dp[layer][i][j] = -INF;
        }
    }
}

void run() {
    int n;
    scanf("%d", &n);

    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        sum += b[i];
    }

    init(0);
    init(1);

    dp[0][0][0] = 0;
    int s = 0, t = 1;
    for (int i = 1; i <= n; ++i) {
        init(t);

        for (int j = 0; j <= i; ++j) {
            for (int k = 0; k < N * N; ++k) {
                dp[t][j][k] = dp[s][j][k];
            }
        }

        for (int j = 1; j <= i; ++j) {
            for (int k = a[i]; k < N * N; ++k) {
                if (dp[s][j - 1][k - a[i]] != -INF) {
                    smax(dp[t][j][k], dp[s][j - 1][k - a[i]] + b[i]);
                }
            }
        }

        std::swap(s, t);
    }

    for (int k = 1; k <= n; ++k) {
        double ans = 0;
        for (int j = 0; j < N * N; ++j) {
            if (dp[s][k][j] == -INF) {
                continue;
            }
            smax(ans, std::min((double)j, (double)(sum + dp[s][k][j]) / 2.0));
        }
        printf("%.20lf ", ans);
    }
    printf("\n");
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