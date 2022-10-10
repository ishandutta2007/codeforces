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
const int N = 200100;

std::vector<int> g[N];
int par[N], tin[N], tout[N];
int timer = 0;

void dfs(int v, int p) {
    par[v] = p;
    tin[v] = timer++;

    for (auto to : g[v]) {
        if (to != p) {
            dfs(to, v);
        }
    }

    tout[v] = timer++;
}

bool isParent(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

void solve() {
    int k;
    scanf("%d", &k);

    std::vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        int cur;
        scanf("%d", &cur);

        a[i] = par[cur - 1];
    }

    std::sort(a.begin(), a.end());
    a.resize(std::unique(a.begin(), a.end()) - a.begin());
    std::sort(a.begin(), a.end(), [&](int v1, int v2) {
        return tin[v1] < tin[v2];
    });

    for (int i = 1; i < (int)a.size(); ++i) {
        int v1 = a[i - 1];
        int v2 = a[i];

        if (!isParent(v1, v2) && !isParent(v2, v1)) {
            printf("NO\n");
            return;
        }
    }

    printf("YES\n");
}

void run() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n - 1; ++i) {
        int from, to;
        scanf("%d%d", &from, &to);

        g[from - 1].push_back(to - 1);
        g[to - 1].push_back(from - 1);
    }

    dfs(0, 0);

    while (m--) {
        solve();
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