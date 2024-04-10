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
const int N = 610;

class Query {
public:
	int from, to;
	int len;

	Query() = default;

	Query(int from, int to, int len) : from(from), to(to), len(len) {}
};

int g[N][N];
ll d[N][N];
std::vector<Query> allQueries[N];
ll maxDiff[N];
bool inAnswer[N][N];

void floyd(int n) {
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (d[i][k] != LINF && d[k][j] != LINF) {
					smin(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}
}

void run() {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j) {
				d[i][j] = LINF;
			}
			g[i][j] = -INF;
		}
	}

	for (int i = 0; i < m; ++i) {
		int from, to, cost;
		scanf("%d%d%d", &from, &to, &cost);

		g[from - 1][to - 1] = cost;
		g[to - 1][from - 1] = cost;

		smin(d[from - 1][to - 1], (ll)cost);
		smin(d[to - 1][from - 1], (ll)cost);
	}    

	int q;
	scanf("%d", &q);

	for (int i = 0; i < q; ++i) {
		int from, to, len;
		scanf("%d%d%d", &from, &to, &len);

		allQueries[from - 1].push_back(Query(from - 1, to - 1, len));
		allQueries[to - 1].push_back(Query(to - 1, from - 1, len));
	}

	floyd(n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			maxDiff[j] = -LINF;
		}

		for (auto& [from, to, len] : allQueries[i]) {
			assert(from == i);

			for (int j = 0; j < n; ++j) {
				smax(maxDiff[j], (ll)len - d[j][to]);
			}
		}

		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (g[j][k] == -INF) {
					continue;
				}
				if (inAnswer[j][k] || inAnswer[k][j]) {
					continue;
				}

				if (maxDiff[k] >= d[i][j] + g[j][k]) {
					inAnswer[j][k] = true;
					inAnswer[k][j] = true;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (inAnswer[i][j]) {
				++ans;
			}
		}
	}

	assert(ans % 2 == 0);

	printf("%d\n", ans / 2);
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