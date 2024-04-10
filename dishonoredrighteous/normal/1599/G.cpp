// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <stdio.h>
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
const int N = 200100;

class Point {
public:
    int x, y;
    int id;

    Point() = default;

    Point(int _x, int _y) : x(_x), y(_y) {}

    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    Point operator+() const {
        return *this;
    }

    Point operator-() const {
        return Point(-x, -y);
    }

    Point operator*(int k) const {
        return Point(x * k, y * k);
    }

    ll operator*(const Point& other) const {
        return 1ll * x * other.x + 1ll * y * other.y;
    }

    ll operator%(const Point& other) const {
        return 1ll * x * other.y - 1ll * y * other.x;
    }

    ll lenSqr() const {
        return 1ll * x * x + 1ll * y * y;
    }

    double len() const {
        return sqrt(lenSqr());
    }

    ll distSqr(const Point& other) const {
        return (other - *this).lenSqr();
    }

    double dist(const Point& other) const {
        return sqrt(distSqr(other));
    }

    // Counterclockwise rotation by 90 degrees
    Point ort() const {
        return Point(-y, x);
    }

    int quad() const {
        if (x >= 0 && y >= 0) {
            return 1;
        } else if (x < 0 && y >= 0) {
            return 2;
        } else if (x < 0 && y < 0) {
            return 3;
        } else if (x >= 0 && y < 0) {
            return 4;
        }
        throw;
    }

    void scan() {
        scanf("%d%d", &x, &y);
    }

    void print() const {
        printf("%d %d\n", x, y);
    }

    bool operator<(const Point& other) const {
    	return x < other.x || (x == other.x && y < other.y);
    }
};

Point a[N];

void run() {
    int n, k;
    scanf("%d%d", &n, &k);
    --k;

    for (int i = 0; i < n; ++i) {
    	a[i].scan();
    	a[i].id = i;
    }

    std::sort(a, a + n);

    int imposterPoint = 0;
    if (n > 3) {
    	Point v = a[1] - a[0];
    	int cnt = 2;

    	int badId = -1;
    	for (int i = 2; i < n; ++i) {
    		Point curV = a[i] - a[0];
    		if (v % curV == 0) {
    			++cnt;
    		} else {
    			badId = i;
    		}
    	}

    	if (cnt == n - 1) {
    		assert(badId != -1);
    		imposterPoint = badId;
    	} else {
    		v = a[n - 1] - a[n - 2];
    		cnt = 2;
    		badId = -1;

    		for (int i = 0; i < n - 2; ++i) {
    			Point curV = a[i] - a[n - 2];
    			if (v % curV == 0) {
    				++cnt;
    			} else {
    				badId = i;
    			}
    		}

    		assert(cnt == n - 1);
    		assert(badId != -1);

    		imposterPoint = badId;
    	}
    }

    // std::cout << a[imposterPoint].id << std::endl;

    std::swap(a[imposterPoint], a[0]);
    std::sort(a + 1, a + n);
    imposterPoint = 0;

    for (int i = 0; i < n; ++i) {
    	if (a[i].id == k) {
    		k = i;
    		break;
    	}
    }

    // a[imposterPoint].print();

    double ans = 1e18;
    if (imposterPoint == k) {
    	smin(ans, a[1].dist(a[n - 1]) + a[1].dist(a[0]));
    	smin(ans, a[1].dist(a[n - 1]) + a[n - 1].dist(a[0]));
    } else {
    	for (int i = 1; i < n; ++i) {
    		double val1 = a[k].dist(a[i]) + a[i].dist(a[1]) + a[1].dist(a[0]);
    		if (i != n - 1) {
    			val1 += a[0].dist(a[i + 1]) + a[i + 1].dist(a[n - 1]);
    		}
    		double val2 = a[k].dist(a[1]) + a[1].dist(a[i]) + a[i].dist(a[0]);
    		if (i != n - 1) {
    			val2 += a[0].dist(a[i + 1]) + a[i + 1].dist(a[n - 1]);
    		}
    		smin(ans, val1);
    		smin(ans, val2);
    	}
    	for (int i = 1; i < n; ++i) {
    		double val1 = a[k].dist(a[i]) + a[i].dist(a[n - 1]) + a[n - 1].dist(a[0]);
 			if (i != 1) {
 				val1 += a[0].dist(a[i - 1]) + a[i - 1].dist(a[1]);
 			}
 			double val2 = a[k].dist(a[n - 1]) + a[n - 1].dist(a[i]) + a[i].dist(a[0]);
 			if (i != 1) {
 				val2 += a[0].dist(a[i - 1]) + a[i - 1].dist(a[1]);
 			}
 			smin(ans, val1);
 			smin(ans, val2);
    	}
    }

    printf("%.10lf\n", ans);
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