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
const int MOD1 = (int)1e9 + 7;
const int MOD2 = 998244353;
const int P = 239;

int add(int a, int b, int MOD) {
    if (a + b >= MOD) {
        return a + b - MOD;
    }
    return a + b;
}

int mul(int a, int b, int MOD) {
    return (int)(1ll * a * b % MOD);
}

void run() {
    fastIO;

    std::string s, good;
    int k;
    std::cin >> s >> good >> k;

    std::set<std::pair<int, int>> setik;
    for (int i = 0; i < (int)s.size(); ++i) {
        std::pair<int, int> hash = std::make_pair(0, 0);
        int badCnt = 0;
        for (int j = i; j < (int)s.size(); ++j) {
            hash.first = add(mul(hash.first, P, MOD1), s[j] - 'a' + 1, MOD1);
            hash.second = add(mul(hash.second, P, MOD2), s[j] - 'a' + 1, MOD2);
            if (good[s[j] - 'a'] != '1') {
                ++badCnt;
            }
            if (badCnt > k) {
                break;
            }
            setik.insert(hash);
        }
    }

    std::cout << setik.size() << '\n';
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