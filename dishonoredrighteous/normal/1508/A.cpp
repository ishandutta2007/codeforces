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
const int N = 100100;

std::string a[3];
int pref[N], suff[N];

void solve() {
    int n;
    std::cin >> n;
    std::cin >> a[0] >> a[1] >> a[2];

    int i = 0, j = 0, k = 0;
    std::string res;
    while (true) {
        if (i == 2 * n || j == 2 * n || k == 2 * n) {
            break;
        }

        if (a[0][i] == a[1][j]) {
            res.push_back(a[0][i]);
            ++i;
            ++j;
        } else if (a[0][i] == a[2][k]) {
            res.push_back(a[0][i]);
            ++i;
            ++k;
        } else {
            res.push_back(a[1][j]);
            ++j;
            ++k;
        }
    }

    if (i == 2 * n) {
        if (j < k) {
            res += a[2].substr(k, 2 * n - k);
        } else {
            res += a[1].substr(j, 2 * n - j);
        }
    } else if (j == 2 * n) {
        if (i < k) {
            res += a[2].substr(k, 2 * n - k);
        } else {
            res += a[0].substr(i, 2 * n - i);
        }
    } else {
        if (i < j) {
            res += a[1].substr(j, 2 * n - j);
        } else {
            res += a[0].substr(i, 2 * n - i);   
        }
    }

    assert((int)res.size() <= 3 * n);
    std::cout << res << '\n';
}

void run() {
    fastIO;

    int t;
    std::cin >> t;

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