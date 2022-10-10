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
int path[N];
int d[N];

void bfs(int s) {
    memset(d, -1, sizeof(d));
    std::queue<int> q;

    d[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (auto to : gr[v]) {
            if (d[to] == -1) {
                d[to] = d[v] + 1;
                q.push(to);
            }
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

    int k;
    scanf("%d", &k);

    for (int i = 0; i < k; ++i) {
        scanf("%d", &path[i]);
        --path[i];
    }

    int s = path[0];
    int t = path[k - 1];

    bfs(t);

    int min = 0, max = 0;
    for (int i = 1; i < k; ++i) {
        int prev = path[i - 1];
        int cur = path[i];

        if (d[prev] != d[cur] + 1) {
            ++min;
            ++max;
        } else {
            int cnt = 0;
            for (auto to : g[prev]) {
                if (d[prev] == d[to] + 1) {
                    ++cnt;
                }
            }

            if (cnt > 1) {
                ++max;
            }
        }
    }

    printf("%d %d\n", min, max);
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