// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <stdio.h>
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

template<size_t N>
class dsu {
public:
    dsu() {
        init();
    }

    void init() {
        for (int i = 0; i < (int)N; ++i) {
            p[i] = i;
            sz[i] = 1;
        }
    }

    int get(int v) {
        if (v == p[v]) {
            return v;
        }
        return p[v] = get(p[v]);
    }

    bool unite(int a, int b) {
        a = get(a);
        b = get(b);

        if (a == b) {
            return false;
        }
        if (sz[a] > sz[b]) {
            std::swap(a, b);
        }

        p[a] = b;
        sz[b] += sz[a];

        return true;
    }

    bool check(int a, int b) {
        return get(a) == get(b);
    }

    int get_size(int a) {
        assert(a == get(a));
        return sz[a];
    }

    int p[N], sz[N];
};

class Edge {
public:
    int from, to, cost;

    Edge() = default;

    Edge(int _from, int _to, int _cost) : from(_from), to(_to), cost(_cost) {}

    bool operator<(const Edge& other) const {
        return cost < other.cost;
    }
};

dsu<N> DSU;
ll res[N];

ll ans = 0;

void run() {
    int n, m;
    scanf("%d%d", &n, &m);

    std::vector<Edge> edges;
    for (int i = 0; i < n - 1; ++i) {
        int from, to, cost;
        scanf("%d%d%d", &from, &to, &cost);
        edges.push_back(Edge(from - 1, to - 1, cost));
    }  

    std::sort(edges.begin(), edges.end());
    std::vector<std::pair<int, int>> queries(m);
    for (int i = 0; i < m; ++i) {
        int q;
        scanf("%d", &q);
        queries[i] = std::make_pair(q, i);
    }

    std::sort(queries.begin(), queries.end());

    int ptr = 0;
    for (auto[cur, id] : queries) {
        while (ptr < (int)edges.size() && edges[ptr].cost <= cur) {
            int s1 = DSU.sz[DSU.get(edges[ptr].from)];
            int s2 = DSU.sz[DSU.get(edges[ptr].to)];
            ans += 1ll * s1 * s2;
            DSU.unite(edges[ptr].from, edges[ptr].to);
            ++ptr;
        }

        res[id] = ans;
    }

    for (int i = 0; i < m; ++i) {
        printf("%lld ", res[i]);
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