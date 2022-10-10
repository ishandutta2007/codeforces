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
const int N = 2100;

int dp[N][N];
int a[N];

void run() {
    int n, h, l, r;
    scanf("%d%d%d%d", &n, &h, &l, &r);

    for (int i = 0; i < n; ++i) {
    	scanf("%d", &a[i]);
    } 

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
    	for (int t = 0; t < h; ++t) {
    		if (dp[i][t] == -1) {
    			continue;
    		}

    		int cur = (t + a[i]) % h;
    		if (cur >= l && cur <= r) {
    			dp[i + 1][cur] = std::max(dp[i + 1][cur], dp[i][t] + 1);
    		} else {
    			dp[i + 1][cur] = std::max(dp[i + 1][cur], dp[i][t]);
    		}

    		cur = (cur - 1 + h) % h;
			if (cur >= l && cur <= r) {
    			dp[i + 1][cur] = std::max(dp[i + 1][cur], dp[i][t] + 1);
    		} else {
    			dp[i + 1][cur] = std::max(dp[i + 1][cur], dp[i][t]);
    		}    		
    	}
    }

    int ans = 0;
    for (int i = 0; i < h; ++i) {
    	ans = std::max(ans, dp[n][i]);
    }

    printf("%d\n", ans);
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