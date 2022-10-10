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

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int a[N];

void solve() {
	int n;
	scanf("%d", &n);

	std::set<int> indexes;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		indexes.insert(i);
	}

	std::set<int> setik;
	for (int i = 1; i < n; ++i) {
		if (gcd(a[i], a[i - 1]) == 1) {
			setik.insert(i);
		}
	}
	if (gcd(a[0], a[n - 1]) == 1) {
		setik.insert(0);
	}

	std::vector<int> ans;
	int id = 1;
	while (!setik.empty()) {
		auto it = setik.lower_bound(id);
		if (it == setik.end()) {
			it = setik.begin();
		}

		int itVal = *it;

		auto next = indexes.lower_bound(itVal);
		if (std::next(next) == indexes.end()) {
			next = indexes.begin();
		} else {
			next = std::next(next);
		}
		auto prev = indexes.lower_bound(itVal);
		if (prev != indexes.begin()) {
			--prev;
		} else {
			prev = indexes.end();
			--prev;
		}

		int prevVal = *prev;
		int nextVal = *next;

		setik.erase(itVal);
		setik.erase(nextVal);

		ans.push_back(itVal);
		indexes.erase(itVal);

		if (indexes.find(nextVal) != indexes.end() && gcd(a[prevVal], a[nextVal]) == 1) {
			setik.insert(nextVal);
		}

		id = nextVal + 1;
	}

	printf("%d", (int)ans.size());
	for (auto i : ans) {
		printf(" %d", i + 1);
	}
	printf("\n");
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