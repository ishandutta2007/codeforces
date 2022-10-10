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

class Query {
public:
    int setId;
    int v;
    int cost;

    Query() = default;

    Query(int setId, int v, int cost) : setId(setId), v(v), cost(cost) {}

    bool operator<(const Query& other) const {
        return cost > other.cost;
    }
};

int p[N], sz[N];

void dsuInit() {
    for (int i = 0; i < N; ++i) {
        p[i] = i;
        sz[i] = 1;
    }
}

int dsuGet(int v) {
    if (v == p[v]) {
        return v;
    }
    return dsuGet(p[v]);
}

void dsuUnite(int a, int b) {
    a = dsuGet(a);
    b = dsuGet(b);

    if (a == b) {
        return;
    }
    if (sz[a] > sz[b]) {
        std::swap(a, b);
    }

    p[a] = b;
    sz[b] += sz[a];
}

int a[N], b[N];
std::vector<int> added[N];

void run() {
    dsuInit();

    int m, n;
    scanf("%d%d", &m, &n);

    for (int i = 0; i < m; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }

    ll ans = 0;
    std::vector<Query> all;
    for (int i = 0; i < m; ++i) {
        int curSz;
        scanf("%d", &curSz);

        while (curSz--) {
            int cur;
            scanf("%d", &cur);
            --cur;

            all.push_back(Query(i, cur, a[i] + b[cur]));
            ans += all.back().cost;
        }
    }

    std::sort(all.begin(), all.end());

    for (auto& [setId, v, cost] : all) {
        if (added[setId].empty()) {
            added[setId].push_back(v);
            ans -= cost;
            continue;
        }

        int from = added[setId].back();
        int to = v;

        if (dsuGet(from) == dsuGet(to)) {
            continue;
        }

        dsuUnite(from, to);
        ans -= cost;
    }

    printf("%lld\n", ans);
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