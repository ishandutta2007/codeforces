// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <random>
#include <chrono>

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
const int N = 1100;

int n;
std::vector<int> g[N];
bool used[N];

int getLCA(int a, int b) {
    printf("? %d %d\n", a + 1, b + 1);
    fflush(stdout);

    int ans;
    scanf("%d", &ans);
    return ans - 1;
}

void answer(int v) {
    printf("! %d\n", v + 1);
    fflush(stdout);
    exit(0);
}

bool dfs(int v, int p = -1) {
    used[v] = true;

    for (auto to : g[v]) {
        if (to != p && !used[to]) {
            dfs(to, v);
        }
    }
}

void run() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n - 1; ++i) {
        int from, to;
        scanf("%d%d", &from, &to);

        g[from - 1].push_back(to - 1);
        g[to - 1].push_back(from - 1);
    }

    while (true) {
        int v1 = -1, v2 = -1;

        for (int i = 0; i < n; ++i) {
            if (used[i]) {
                continue;
            }

            int cnt = 0;
            for (auto to : g[i]) {
                if (!used[to]) {
                    ++cnt;
                }
            }

            if (cnt == 0) {
                answer(i);
            }

            if (cnt == 1) {
                if (v1 == -1) {
                    v1 = i;
                } else {
                    v2 = i;
                }
            }
        }

        int lca = getLCA(v1, v2);

        used[lca] = true;
        dfs(v1);
        used[lca] = false;

        used[lca] = true;
        dfs(v2);
        used[lca] = false;
    }
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