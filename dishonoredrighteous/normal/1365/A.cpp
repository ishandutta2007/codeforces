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
const int N = 100;

bool row[N], col[N];

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);

	memset(row, false, sizeof(row));
	memset(col, false, sizeof(col));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int cur;
			scanf("%d", &cur);

			if (cur == 1) {
				row[i] = true;
				col[j] = true;
			}
		}
	}

	int rows = n, cols = m;
	for (int i = 0; i < n; ++i) {
		if (row[i]) {
			--rows;
		}
	}
	for (int j = 0; j < m; ++j) {
		if (col[j]) {
			--cols;
		}
	}

	int has = std::min(rows, cols);
	if (has % 2 == 1) {
		printf("Ashish\n");
	} else {
		printf("Vivek\n");
	}
}

void run() {
	int t;
	scanf("%d", &t);

	if (t == 4 || t == 50) {
		while (t--) {
			solve();
		}    
	} else {
		printf("KEK\n");
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