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
const int INF = (int)2e9 + 100;
const ll LINF = (ll)2e18;
const int N = 1 << 18;

class Item {
public:
    int x, cost;

    Item() = default;

    Item(int x, int cost) : x(x), cost(cost) {}

    bool operator<(const Item& other) const {
        return x < other.x;
    }
};

class Monster {
public:
    int x, y, z;

    bool operator<(const Monster& other) const {
        return x < other.x;
    }
};

class Segment {
public:
    int max, push, l, r;

    Segment() : max(-INF), push(0), l(-1), r(-1) {}

    Segment(int value, int l, int r) : max(value), push(0), l(l), r(r) {}

    Segment operator+(const Segment& other) const {
        return Segment(std::max(max, other.max), l, other.r);
    }
};

Segment tree[2 * N];

void makePush(int v) {
    if (tree[v].push == 0) {
        return;
    }

    if (v < N) {
        tree[v * 2].push += tree[v].push;
        tree[v * 2 + 1].push += tree[v].push;
    }

    tree[v].max += tree[v].push;
    tree[v].push = 0;
}

void build(int* arr) {
    for (int i = 0; i < N; ++i) {
        tree[i + N] = Segment(arr[i], i, i + 1);
    }
    for (int i = N - 1; i > 0; --i) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}

Segment get(int v, int l, int r) {
    makePush(v);

    if (tree[v].r <= l || r <= tree[v].l) {
        return Segment();
    }
    if (l <= tree[v].l && tree[v].r <= r) {
        return tree[v];
    }

    return get(v * 2, l, r) + get(v * 2 + 1, l, r);
}

void add(int v, int l, int r, int delta) {
    makePush(v);

    if (tree[v].r <= l || r <= tree[v].l) {
        return;
    }
    if (l <= tree[v].l && tree[v].r <= r) {
        tree[v].push += delta;
        makePush(v);
        return;
    }

    add(v * 2, l, r, delta);
    add(v * 2 + 1, l, r, delta);

    tree[v] = tree[v * 2] + tree[v * 2 + 1];
}

Item a[N], b[N];
Monster c[N];
std::vector<int> trans;
int arr[N];

void run() {
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);

    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].x, &a[i].cost);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &b[i].x, &b[i].cost);
    }
    for (int i = 0; i < p; ++i) {
        scanf("%d%d%d", &c[i].x, &c[i].y, &c[i].z);
    }

    std::sort(a, a + n);
    std::sort(b, b + m);
    std::sort(c, c + p);

    for (int i = 0; i < N; ++i) {
        arr[i] = -INF;
    }
    for (int i = 0; i < m; ++i) {
        arr[i] = -b[i].cost;
    }
    build(arr);

    int ptr = 0;
    int ans = -INF;
    for (int i = 0; i < n; ++i) {
        int curX = a[i].x;

        while (ptr < p && curX > c[ptr].x) {
            int id = std::upper_bound(b, b + m, Item(c[ptr].y, -1)) - b;
            add(1, id, m, c[ptr].z);
            ++ptr;
        }

        int curCost = -a[i].cost + get(1, 0, m).max;
        ans = std::max(ans, curCost);

        // debug(curCost);
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