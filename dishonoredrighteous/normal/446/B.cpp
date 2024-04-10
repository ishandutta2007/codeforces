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
const int M = 1000100;

int a[N][N];
ll rowSum[N], colSum[N];
ll bestRow[M], bestCol[M];

void run() {
	int n, m, k, p;
	scanf("%d%d%d%d", &n, &m, &k, &p);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
			rowSum[i] += a[i][j];
			colSum[j] += a[i][j];
		}
	}    

	std::multiset<int> setik;
	for (int i = 0; i < n; ++i) {
		setik.insert(rowSum[i]);
	}
	ll prev = 0;
	for (int i = 1; i <= k; ++i) {
		int cur = *setik.rbegin();
		setik.erase(setik.find(cur));

		prev += cur;
		bestRow[i] = prev;
		cur -= m * p;

		setik.insert(cur);
	}

	setik.clear();
	for (int i = 0; i < m; ++i) {
		setik.insert(colSum[i]);
	}
	prev = 0;
	for (int i = 1; i <= k; ++i) {
		int cur = *setik.rbegin();
		setik.erase(setik.find(cur));

		prev += cur;
		bestCol[i] = prev;
		cur -= n * p;

		setik.insert(cur);
	}

	ll best = -LINF;
	for (int i = 0; i <= k; ++i) {
		best = std::max(best, bestRow[i] + bestCol[k - i] - 1ll * i * (k - i) * p);
	}

	printf("%lld\n", best);
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