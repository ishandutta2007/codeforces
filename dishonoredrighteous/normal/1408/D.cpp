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
const int N = 2100;
const int M = 1000100;

class Point {
public:
    int x, y;

    Point() = default;

    Point(int x, int y) : x(x), y(y) {}
};

Point a[N], b[N];
int delta[M];

void run() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &b[i].x, &b[i].y);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (b[j].x < a[i].x || b[j].y < a[i].y) {
                continue;
            }

            int dx = b[j].x - a[i].x;
            int dy = b[j].y - a[i].y;
            delta[dx] = std::max(delta[dx], dy + 1);
        }
    }

    for (int i = M - 2; i >= 0; --i) {
        delta[i] = std::max(delta[i], delta[i + 1]);
    }

    int ans = INF;
    for (int i = 0; i < M; ++i) {
        ans = std::min(ans, i + delta[i]);
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