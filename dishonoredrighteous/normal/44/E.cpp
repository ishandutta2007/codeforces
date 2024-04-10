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
const int N = 210;

char s[N];

void run() {
    int k, a, b;
    scanf("%d%d%d\n%s", &k, &a, &b, s);

    int n = strlen(s);

    int sz = n / k;
    if (sz < a || sz > b) {
    	printf("No solution\n");
    	return;
    }
    if (n % k != 0 && (sz + 1 < a || sz + 1 > b)) {
    	printf("No solution\n");
    	return;
    }

    int cnt = n % k;
    int ptr = 0;
    while (cnt--) {
    	for (int i = ptr; i < ptr + n / k + 1; ++i) {
    		printf("%c", s[i]);
    	}
    	printf("\n");
    	ptr += n / k + 1;
    }

    while (ptr < n) {
    	for (int i = ptr; i < ptr + n / k; ++i) {
    		printf("%c", s[i]);
    	}
    	printf("\n");
    	ptr += n / k;
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