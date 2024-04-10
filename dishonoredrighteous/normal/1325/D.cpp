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

void build(ll s, ll x) {
	ll ans1 = 0, ans2 = 0;

	bool need = false;
	for (int i = 60; i >= 0; --i) {
		int cnt = 0;
		if (need) {
			if (((x >> i) & 1) == 0) {
				ans1 ^= 1ll << i;
				ans2 ^= 1ll << i;
				need = false;
				cnt += 2;
			} else {
				ans1 ^= 1ll << i;
				++cnt;
			}
		}

		if (((s >> i) & 1) == 1) {
			if (cnt == 0) {

			}
		}
	}
}

void run() {
	ll a, b;
	scanf("%lld%lld", &a, &b);

	if (b < a) {
		printf("-1\n");
		return;
	}    

	if (a == b) {
		if (a == 0) {
			printf("0\n");
		} else {
			printf("1\n%lld\n", a);
		}
		return;
	}

	ll delta = b - a;

	if (delta % 2 == 1) {
		printf("-1\n");
		return;
	}

	delta /= 2;

	bool fl = false;
	for (int i = 0; i <= 60; ++i) {
		int bit1 = ((delta >> i) & 1);
		int bit2 = ((a >> i) & 1);

		if (bit1 == 1 && bit2 == 1) {
			fl = true;
		}
	}

	if (fl) {
		printf("3\n%lld %lld %lld\n", delta, delta, a);
	} else {
		printf("2\n%lld %lld\n", a + delta, delta);
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