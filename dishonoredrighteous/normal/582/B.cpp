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
const int N = 310;

class matrix {
public:
    matrix() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                a[i][j] = -INF;
            }
        }
    }

    matrix(bool one) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                a[i][j] = -INF;
            }
        }
        if (one) {
            for (int i = 0; i < N; ++i) {
                a[i][i] = 0;
            }
        }
    }

    matrix operator*(const matrix& other) const {
        matrix res;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                res.a[i][j] = -INF;
                for (int k = 0; k < N; ++k) {
                    smax(res.a[i][j], a[i][k] + other.a[k][j]);
                }
            }
        }
        return res;
    }

    int a[N][N];
};

matrix binpow(matrix& a, int n) {
    matrix res(true);
    while (n > 0) {
        if (n % 2 == 1) {
            res = res * a;
        }
        a = a * a;
        n /= 2;
    }
    return res;
}

int a[N];
int dp[N][N];

void run() {
    int n, t;
    scanf("%d%d", &n, &t);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    // a[i][j]  length if the first element is >= i and last element = j
    matrix mt;
    for (int start = 0; start < n; ++start) {
        for (int end = 0; end < n; ++end) {
            if (a[start] > a[end]) {
                mt.a[start][end] = -INF;
                continue;
            }

            mt.a[start][end] = 1;
            for (int prev = 0; prev < end; ++prev) {
                if (a[prev] <= a[end]) {
                    smax(mt.a[start][end], mt.a[start][prev] + 1);
                }
            }
        }
    }

    mt = binpow(mt, t);
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            smax(ans, mt.a[i][j]);
        }
    }

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