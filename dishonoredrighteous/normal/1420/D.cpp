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
const int N = 300100;
const int MOD = 998244353;

int add(int a, int b) {
    if (a + b >= MOD) {
        return a + b - MOD;
    }
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) {
        return a - b + MOD;
    }
    return a - b;
}

int mul(int a, int b) {
    return (int)(1ll * a * b % MOD);
}

int binpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n /= 2;
    }
    return res;
}

int inv(int a) {
    return binpow(a, MOD - 2);
}

int f[N], rf[N];

void precalc() {
    f[0] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = mul(f[i - 1], i);
    }
    rf[N - 1] = inv(f[N - 1]);
    for (int i = N - 2; i >= 0; --i) {
        rf[i] = mul(rf[i + 1], i + 1);
    }

    for (int i = 0; i < N; ++i) {
        assert(mul(f[i], rf[i]) == 1);
    }
}

int choose(int n, int k) {
    if (k < 0 || k > n || n < 0) {
        return 0;
    }
    return mul(f[n], mul(rf[k], rf[n - k]));
}

class Event {
public:
    int x, type;

    Event() = default;

    Event(int _x, int _type) : x(_x), type(_type) {}

    bool operator<(const Event& other) const {
        return x < other.x || (x == other.x && type > other.type);
    }
};

void run() {
    precalc();

    int n, k;
    scanf("%d%d", &n, &k);

    std::vector<Event> events;
    for (int i = 0; i < n; ++i) {
        int l, r;
        scanf("%d%d", &l, &r);
        events.push_back(Event(l, 1));
        events.push_back(Event(r, -1));
    }

    std::sort(events.begin(), events.end());

    int ans = 0;
    int opened = 0;
    for (auto[x, type] : events) {
        if (type == 1) {
            ++opened;
            if (opened >= k) {
                ans = add(ans, choose(opened - 1, k - 1));
            }
        } else {
            --opened;
        }
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