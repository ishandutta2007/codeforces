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
const int N = 100100;

std::vector<int> f[N];
int ans[N];
int used[N];

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; ++i) {
		f[i].clear();
		ans[i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		used[i] = 0;
	}

	for (int i = 0; i < m; ++i) {
		int k;
		scanf("%d", &k);

		while (k--) {
			int cur;
			scanf("%d", &cur);
			f[i].push_back(cur - 1);
		}

		++used[f[i][0]];
	}

	int maxUsed = 0;
	int maxId = -1;
	for (int i = 0; i < n; ++i) {
		if (smax(maxUsed, used[i])) {
			maxId = i;
		}
	}

	if (maxUsed > (m + 1) / 2) {
		for (int i = 0; i < m; ++i) {
			if (f[i].size() <= 1) {
				continue;
			}
			if (f[i][ans[i]] == maxId) {
				--maxUsed;
				++ans[i];

				if (maxUsed <= (m + 1) / 2) {
					break;
				}
			}
		}
	}

	if (maxUsed > (m + 1) / 2) {
		printf("NO\n");
	} else {
		printf("YES\n");

		for (int i = 0; i < m; ++i) {
			printf("%d ", f[i][ans[i]] + 1);
		}
		printf("\n");
	}
}

void run() {
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