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
const int N = 100100;

int cnt[N];

void run() {
    int n;
    scanf("%d", &n);

    int ans = 0;
    std::multiset<std::pair<int, int>> setik;
    for (int i = 0; i < n; ++i) {
        int cur;
        scanf("%d", &cur);

        auto pref = setik.find(std::make_pair(cnt[cur], cur));

        if (pref != setik.end()) {
            setik.erase(setik.find(std::make_pair(cnt[cur], cur)));
        }
        ++cnt[cur];
        setik.insert(std::make_pair(cnt[cur], cur));

        if (setik.size() == 1) {
            ans = i + 1;
        } else {
            if (setik.rbegin()->first - setik.begin()->first == 1) {
                auto last = *setik.rbegin();
                setik.erase(setik.find(last));

                if (setik.rbegin()->first - setik.begin()->first == 0) {
                    ans = i + 1;
                }

                setik.insert(last);
            }

            if (setik.begin()->first == 1) {
                auto first = *setik.begin();
                setik.erase(setik.find(first));

                if (setik.rbegin()->first - setik.begin()->first == 0) {
                    ans = i + 1;
                }

                setik.insert(first);
            }
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