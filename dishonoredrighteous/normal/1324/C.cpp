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

char s[N];

bool check(int n, int d) {
	int l = 1;
	int r = std::min(d, n + 1);

	while (r < n + 1) {
		int right = -1;
		for (int i = l; i <= r; ++i) {
			if (s[i] == 'R') {
				right = i;
			}
		}

		if (right == -1) {
			return false;
		} 

		l = r + 1;
		r = std::min(n + 1, right + d);
	}

	return true;
}

void solve() {
	scanf("\n%s", s);
	int n = strlen(s);

	for (int i = n; i > 0; --i) {
		s[i] = s[i - 1];
	}

	int l = 0, r = n + 1;
	while (r - l > 1) {
		int m = (l + r) / 2;
		if (check(n, m)) {
			r = m;
		} else {
			l = m;
		}
	}

	printf("%d\n", r);
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