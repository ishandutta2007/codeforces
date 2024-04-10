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

std::pair<int, int> a[N];
std::vector<int> all;
int cnt[4 * N], pref[4 * N];

int get(int x) {
    return std::lower_bound(all.begin(), all.end(), x) - all.begin();
}

void run() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].first, &a[i].second);

        all.push_back(a[i].first);
        all.push_back(a[i].second);
        all.push_back(a[i].second + 1);
        all.push_back(a[i].first - 1);
    }

    std::sort(all.begin(), all.end());
    all.resize(std::unique(all.begin(), all.end()) - all.begin());

    for (int i = 0; i < n; ++i) {
        ++cnt[get(a[i].first)];
        --cnt[get(a[i].second + 1)];
    }

    for (int i = 1; i < 4 * N; ++i) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < 4 * N; ++i) {
        if (cnt[i] == 1) {
            pref[i] = 1;
        }
    }
    for (int i = 1; i < 4 * N; ++i) {
        pref[i] += pref[i - 1];
    }

    for (int i = 0; i < n; ++i) {
        int cur = pref[get(a[i].second)] - pref[get(a[i].first - 1)];
        if (cur == 0) {
            printf("%d\n", i + 1);
            return;
        }
    }

    printf("-1\n");
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