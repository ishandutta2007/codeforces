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
const int MOD = (int)1e9 + 7;

int add(int a, int b) {
    if (a + b >= MOD) {
        return a + b - MOD;
    }
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) {
        return a - b + MOD;
    }
    return a - b;
}

int mul(int a, int b) {
    return (int)(1ll * a * b % MOD);
}

int binpow(int a, int n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        return binpow(mul(a, a), n / 2);
    } else {
        return mul(binpow(a, n - 1), a);
    }
}

int inv(int a) {
    return binpow(a, MOD - 2);
}

int a[N];
int ans[2 * N];
int shitUp[2 * N];

void run() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n - 1; ++i) {
        scanf("%d", &a[i]);
    }

    int r2 = inv(2);
    int vCnt = 1;
    for (int i = 0; i < n; ++i) {
        int cur = 1;
        for (int goUp = 1; goUp <= i; ++goUp) {
            ans[goUp * 2] = add(ans[goUp * 2], mul(mul(cur, sub(a[i - goUp], 1)), mul(r2, vCnt)));
            shitUp[goUp * 2] = add(shitUp[goUp * 2], mul(mul(cur, sub(a[i - goUp], 1)), vCnt));
            cur = mul(cur, a[i - goUp]);
        }

        shitUp[0] = vCnt;
        for (int d = n * 2 - 2; d >= 1; --d) {
            shitUp[d] = mul(shitUp[d - 1], a[i]);
        }
        
        for (int d = 1; d <= n * 2 - 2; ++d) {
            ans[d] = add(ans[d], shitUp[d]);
        }

        vCnt = mul(vCnt, a[i]);
    }

    for (int i = 1; i <= 2 * n - 2; ++i) {
        printf("%d ", ans[i]);
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