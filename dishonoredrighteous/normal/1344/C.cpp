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

std::vector<int> g[N], gr[N];
int used[N];
bool used1[N], used2[N];
bool good[N];

void no() {
    printf("-1\n");
    exit(0);
}

void findCycle(int v) {
    used[v] = 1;

    for (auto to : g[v]) {
        if (used[to] == 0) {
            findCycle(to);
        } else if (used[to] == 1) {
            no();
        }
    }

    used[v] = 2;
}

void dfsG(int v) {
    used1[v] = true;
    good[v] = false;

    for (auto to : g[v]) {
        if (!used1[to]) {
            dfsG(to);
        }
    }
}

void dfsGR(int v) {
    used2[v] = true;
    good[v] = false;

    for (auto to : gr[v]) {
        if (!used2[to]) {
            dfsGR(to);
        }
    }
}

void run() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int from, to;
        scanf("%d%d", &from, &to);

        g[from - 1].push_back(to - 1);
        gr[to - 1].push_back(from - 1);
    }    

    for (int i = 0; i < n; ++i) {
        if (used[i] == 0) {
            findCycle(i);
        }
    }

    memset(good, true, sizeof(good));

    std::string ans;
    for (int i = 0; i < n; ++i) {
        if (good[i]) {
            ans.push_back('A');
        } else {
            ans.push_back('E');
        }

        if (!used1[i]) {
            dfsG(i);
        }
        if (!used2[i]) {
            dfsGR(i);
        }
    }

    printf("%d\n", (int)std::count(ans.begin(), ans.end(), 'A'));
    printf("%s\n", ans.c_str());
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