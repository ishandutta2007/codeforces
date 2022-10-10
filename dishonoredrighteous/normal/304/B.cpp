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

bool isLeap(int n) {
    return (n % 4 == 0 && n % 100 != 0) || n % 400 == 0;
}

int normDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leapDays[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int get(int y, int m, int d) {
    int curY = 1900, curM = 0, curD = 0;
    int ans = 0;

    while (curY < y) {
        if (isLeap(curY)) {
            ans += 366;
        } else {
            ans += 365;
        }
        ++curY;
    }

    while (curM < m) {
        if (isLeap(curY)) {
            ans += leapDays[curM];
        } else {
            ans += normDays[curM];
        }
        ++curM;
    }

    ans += d;

    return ans;
}

void run() {
    int d1, m1, y1;
    int d2, m2, y2;
    scanf("%d:%d:%d\n%d:%d:%d", &y1, &m1, &d1, &y2, &m2, &d2);

    --m1;
    --m2;

    printf("%d\n", abs(get(y1, m1, d1) - get(y2, m2, d2)));
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