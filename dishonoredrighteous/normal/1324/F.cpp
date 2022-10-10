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
int color[N];
int cnt[N][2];
int best[N];
int ans[N];

void precalc(int v, int p) {
	++cnt[v][color[v]];

	if (color[v] == 1) {
		best[v] = 1;
	} else {
		best[v] = -1;
	}

	for (auto to : g[v]) {
		if (to != p) {
			precalc(to, v);

			cnt[v][0] += cnt[to][0];
			cnt[v][1] += cnt[to][1];

			if (best[to] >= 0) {
				best[v] += best[to];
			}
		}
	}
}

void dfs(int v, int p, int up) {
	ans[v] = best[v];
	if (up >= 0) {
		ans[v] += up;
	}

	int sum = 0;
	if (up >= 0) {
		sum += up;
	}

	if (color[v] == 1) {
		++sum;
	} else {
		--sum;
	}

	for (auto to : g[v]) {
		if (to != p && best[to] >= 0) {
			sum += best[to];
		}
	}

	for (auto to : g[v]) {
		if (to != p) {
			if (best[to] >= 0) {
				dfs(to, v, sum - best[to]);
			} else {
				dfs(to, v, sum);
			}
		}
	}
}

void run() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &color[i]);
	}

	for (int i = 0; i < n - 1; ++i) {
		int from, to;
		scanf("%d%d", &from, &to);

		g[from - 1].push_back(to - 1);
		g[to - 1].push_back(from - 1);
	}

	precalc(0, -1);
	dfs(0, -1, 0);

	for (int i = 0; i < n; ++i) {
		printf("%d ", ans[i]);
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