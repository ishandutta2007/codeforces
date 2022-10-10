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
const int N = 300100;

class Query {
public:
	int id;
	ll pref, ans;

	Query() = default;

	Query(int id, ll pref, ll ans) : id(id), pref(pref), ans(ans) {}
};

int h[N], b[N];

void run() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &h[i]);
	}    
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}

	ll ans = b[1];
	std::stack<Query> st;
	st.push(Query(1, 0ll, ans));

	for (int i = 2; i <= n; ++i) {
		Query cur(i, ans, ans + b[i]);
		while (!st.empty() && h[st.top().id] > h[i]) {
			smax(cur.pref, st.top().pref);
			st.pop();
		}

		smax(cur.ans, cur.pref + b[i]);
		if (!st.empty()) {
			smax(cur.ans, st.top().ans);
		}

		st.push(cur);
		ans = cur.ans;
	}

	printf("%lld\n", ans);
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