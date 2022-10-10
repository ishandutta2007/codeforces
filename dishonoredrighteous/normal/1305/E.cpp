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
const int N = 5000 * 5000 + 100;

int cnt[N];
bool used[N];

void run() {
    int n, m;
    scanf("%d%d", &n, &m);

    if (n <= 2) {
        if (m != 0) {
            printf("-1\n");
        } else {
            for (int i = 1; i <= n; ++i) {
                printf("%d ", i);
            }
            printf("\n");
        }
        return;
    }    

    std::vector<int> ans;

    ans.push_back(1);
    ans.push_back(2);
    used[1] = true;
    used[2] = true;

    cnt[3] = 1;

    if (m != 0) {
        for (int i = 3; i <= n; ++i) {
            if (m > cnt[i]) {
                ans.push_back(i);
                m -= cnt[i];

                used[i] = true;

                for (auto j : ans) {
                    if (i + j < N) {
                        ++cnt[i + j];
                    }
                }
                if (i + i < N) {
                    --cnt[i + i];
                }
                continue;
            }

            int j = i;
            while (cnt[j] != m && j != N) {
                ++j;
            }

            if (j == N) {
                throw 228;
            }

            ans.push_back(j);
            used[j] = true;

            for (auto l : ans) {
                if (l + j < N) {
                    ++cnt[l + j];
                }
            }
            if (j + j < N) {
                --cnt[j + j];
            }

            m = 0;
            break;
        }
    }

    if (m != 0) {
        printf("-1\n");
        return;
    }

    int cur = 1;
    while ((int)ans.size() < n) {
        while (used[cur] || cnt[cur] > 0) {
            ++cur;
        }

        ans.push_back(cur);
        used[cur] = true;

        for (auto i : ans) {
            if (i + cur < N) {
                ++cnt[i + cur];
            }
        }
        if (cur + cur < N) {
            --cnt[cur + cur];
        }
    }

    for (auto i : ans) {
        printf("%d ", i);
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