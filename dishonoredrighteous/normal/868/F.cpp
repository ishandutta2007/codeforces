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
const int N = 100100;
const int K = 25;

int a[N];
ll dp[K][N];
int cnt[N];
ll curScore = 0;
int curL = 0, curR = -1;

void add(int pos) {
    curScore += cnt[a[pos]];
    ++cnt[a[pos]];
}

void del(int pos) {
    --cnt[a[pos]];
    curScore -= cnt[a[pos]];
}

void makeSegment(int l, int r) {
    while (curL > l) {
        --curL;
        add(curL);
    }
    while (curR < r) {
        ++curR;
        add(curR);
    }
    while (curL < l) {
        del(curL);
        ++curL;
    }
    while (curR > r) {
        del(curR);
        --curR;
    }
}

void clear() {
    memset(cnt, 0, sizeof(cnt));
    curL = 0, curR = -1;
    curScore = 0;
}

void calc(int t, int l, int r, int optL, int optR) {
    if (l >= r) {
        return;
    }

    int m = (l + r) / 2;
    dp[t][m] = LINF;

    int curOpt = -1;
    for (int i = std::min(optR, m); i >= optL; --i) {
        makeSegment(i, m);
        ll curVal = curScore;
        if (i != 0) {
            curVal += dp[t - 1][i - 1];
        }
        if (smin(dp[t][m], curVal)) {
            curOpt = i;
        }
    }

    calc(t, l, m, optL, curOpt);
    calc(t, m + 1, r, curOpt, optR);
}

void run() {
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; ++i) {
        makeSegment(0, i);
        dp[1][i] = curScore;
    }

    // for (int t = 2; t <= k; ++t) {
    //     for (int i = 0; i < n; ++i) {
    //         dp[t][i] = LINF;
    //         clear();
    //         for (int j = i; j >= 0; --j) {
    //             makeSegment(j, i);
    //             ll curVal = curScore;
    //             if (j != 0) {
    //                 curVal += dp[t - 1][j - 1];
    //             }
    //             smin(dp[t][i], curVal);
    //         }
    //     }
    // }

    for (int t = 2; t <= k; ++t) {
        clear();
        calc(t, 0, n, 0, n - 1);
    }

    printf("%lld\n", dp[k][n - 1]);
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