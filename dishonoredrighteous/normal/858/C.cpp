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

bool isBad(char c) {
    return c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u';
}

void run() {
    fastIO;

    std::string str;
    std::cin >> str;
    std::string buffer;
    for (int i = 0; i < (int)str.size(); ++i) {
        buffer += str[i];

        if ((int)buffer.size() < 3) {
            continue;
        }

        int k = (int)buffer.size();
        if (isBad(buffer[k - 1]) && isBad(buffer[k - 2]) && isBad(buffer[k - 3]) && (buffer[k - 1] != buffer[k - 2] || buffer[k - 2] != buffer[k - 3])) {
            char cur = buffer.back();
            buffer.pop_back();
            std::cout << buffer << ' ';
            buffer = "";
            buffer.push_back(cur);
        }
    }

    if (!buffer.empty()) {
        std::cout << buffer;
    }
    std::cout << '\n';
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