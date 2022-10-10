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
const int N = 1100;

std::vector<int> rev(const std::vector<int>& p) {
    std::vector<int> q(p.size());
    for (int i = 0; i < (int)p.size(); ++i) {
        q[p[i]] = i;
    }
    for (int i = 0; i < (int)p.size(); ++i) {
        assert(p[q[i]] == i);
    }
    return q;
}

int a[N][N], b[N][N];
char cmd[100100];

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a[i][j]);
            --a[i][j];
        }
    }

    scanf("\n%s", cmd);

    int di = 0, dj = 0, dij = 0;
    int cur[3] = {0, 1, 2};
    for (int i = 0; i < m; ++i) {
        if (cmd[i] == 'R') {
            ++dj;
        }
        if (cmd[i] == 'L') {
            --dj;
        }
        if (cmd[i] == 'D') {
            ++di;
        }
        if (cmd[i] == 'U') {
            --di;
        }
        if (cmd[i] == 'I') {
            std::swap(dj, dij);
            std::swap(cur[1], cur[2]);
        }
        if (cmd[i] == 'C') {
            std::swap(di, dij);
            std::swap(cur[0], cur[2]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int newI, newJ, newVal;

            if (cur[0] == 0) {
                newI = i;
            } else if (cur[0] == 1) {
                newI = j;
            } else {
                newI = a[i][j];
            }

            if (cur[1] == 0) {
                newJ = i;
            } else if (cur[1] == 1) {
                newJ = j;
            } else {
                newJ = a[i][j];
            }

            if (cur[2] == 0) {
                newVal = i;
            } else if (cur[2] == 1) {
                newVal = j;
            } else {
                newVal = a[i][j];
            }

            newI = ((newI + di) % n + n) % n;
            newJ = ((newJ + dj) % n + n) % n;
            newVal = ((newVal + dij) % n + n) % n;

            b[newI][newJ] = newVal;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", b[i][j] + 1);
        }
        printf("\n");
    }

    printf("\n");
}

void run() {
    // int n;
    // scanf("%d", &n);

    // std::vector<int> p(n);
    // for (int i = 0; i < n; ++i) {
    //     scanf("%d", &p[i]);
    //     --p[i];
    // }

    // p = rev(p);

    // for (auto i : p) {
    //     printf("%d ", i + 1);
    // }
    // printf("\n");

    int t;
    scanf("%d", &t);

    while (t--) {
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