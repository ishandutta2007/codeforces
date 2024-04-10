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
const int N = 1 << 19;

class Segment {
public:
    int max, push, l, r;

    Segment() : max(-INF), push(0), l(-1), r(-1) {}

    Segment(int val, int l, int r) : max(val), push(0), l(l), r(r) {}

    Segment operator+(const Segment& other) const {
        return Segment(std::max(max, other.max), l, other.r);
    }
};

Segment tree[2 * N];
int p[N], revP[N], q[N];

void build(int s) {
    for (int i = 0; i < N; ++i) {
        if (i < revP[s]) {
            tree[i + N] = Segment(1, i, i + 1);
        } else {
            tree[i + N] = Segment(0, i, i + 1);
        }
    }
    for (int i = N - 1; i > 0; --i) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}

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

void run() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &p[i]);
        revP[p[i]] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &q[i]);
    }

    build(n);

    int ans = n;
    for (int i = 0; i < n; ++i) {
        printf("%d ", ans);
        add(1, 0, q[i], -1);

        if (get(1, 0, N).max != 0) {
            continue;
        }

        while (get(1, 0, N).max == 0 && ans != 0) {
            add(1, 0, revP[ans - 1], +1);
            --ans;
        }
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