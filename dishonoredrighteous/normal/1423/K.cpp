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
const int N = 1000100;

bool isPrime[N];
int primes[N];

void build() {
	for (int i = 2; i < N; ++i) {
		isPrime[i] = true;
	}
	for (int i = 2; i < N; ++i) {
		if (isPrime[i]) {
			for (ll j = 1ll * i * i; j < N; j += i) {
				isPrime[j] = false;
			}
		}
	}

	for (int i = 1; i < N; ++i) {
		primes[i] = primes[i - 1];
		if (isPrime[i]) {
			++primes[i];
		}
	}
}

void solve() {
	int n;
	scanf("%d", &n);
	printf("%d\n", primes[n] - primes[(int)sqrt(n)] + 1);
}

void run() {
	build();

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