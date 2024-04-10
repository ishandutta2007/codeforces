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
const int N = 100100;

std::vector<std::pair<int, int>> g[N];
int ans[N];
int cur = 0;
int max;

void dfs(int v, int p) {
	if (g[v].size() == 1 && p != -1) {
		ans[g[v].back().second] = cur;
		++cur;
		return;
	}

	int parentId = -1;
	for (auto i : g[v]) {
		int to = i.first, id = i.second;

		if (to == p) {
			parentId = id;
			continue;
		}

		dfs(to, v);
	}

	if (parentId != -1) {
		ans[parentId] = max;
		--max;
	}
}

void run() {
	int n;
	scanf("%d", &n);

	max = n - 2;

	for (int i = 0; i < n - 1; ++i) {
		int from, to;
		scanf("%d%d", &from, &to);

		g[from - 1].push_back(std::make_pair(to - 1, i));
		g[to - 1].push_back(std::make_pair(from - 1, i));
	}

	dfs(0, -1);

	for (int i = 0; i < n - 1; ++i) {
		printf("%d\n", ans[i]);
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