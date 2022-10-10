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
const int N = 1100;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int n, m;
char a[N][N];
bool used[N][N];

bool isCorrect(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '#';
}

void dfs(int x, int y) {
    used[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isCorrect(newX, newY) && !used[newX][newY]) {
            dfs(newX, newY);
        }
    }
}

void no() {
    printf("-1\n");
    exit(0);
}

int left[N], right[N], up[N], down[N];
bool row[N], col[N];

void run() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("\n%s", a[i]);
    }

    for (int i = 0; i < N; ++i) {
        left[i] = INF;
        right[i] = -INF;

        up[i] = INF;
        down[i] = -INF;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '#') {
                left[i] = std::min(left[i], j);
                right[i] = std::max(right[i], j);

                up[j] = std::min(up[j], i);
                down[j] = std::max(down[j], i);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = left[i]; j <= right[i]; ++j) {
            if (a[i][j] == '.') {
                no();
            }
        }
    }

    for (int j = 0; j < m; ++j) {
        for (int i = up[j]; i <= down[j]; ++i) {
            if (a[i][j] == '.') {
                no();
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '.') {
                continue;
            }

            if (!used[i][j]) {
                dfs(i, j);
                ++ans;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (used[i][j]) {
                row[i] = true;
                col[j] = true;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!row[i] && !col[j]) {
                used[i][j] = true;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        bool has = false;
        for (int j = 0; j < m; ++j) {
            if (used[i][j]) {
                has = true;
            }
        }

        if (!has) {
            no();
        }
    }

    for (int j = 0; j < m; ++j) {
        bool has = false;
        for (int i = 0; i < n; ++i) {
            if (used[i][j]) {
                has = true;
            }
        }

        if (!has) {
            no();
        }
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