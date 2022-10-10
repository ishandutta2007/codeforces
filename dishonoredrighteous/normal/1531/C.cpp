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

void run() {
    int n;
    scanf("%d", &n);
    // for (int curN = 3; curN <= 100; ++curN) {
        // int n = curN;
        int curN = n;
        if (n == 2) {
            printf("-1\n");
            return;
        }    

        int w = 0;
        while (w * w < n) {
            ++w;
        }

        // printf("%d\n", w);
        std::vector<std::string> a(w, std::string(w, '.'));
        for (int j = 0; j < w; ++j) {
            assert(n >= 0);

            if (n == 0) {
                break;
            }

            if (a[w - j - 1][j] == '.') {
                if (n % 2 == 1) {
                    a[w - j - 1][j] = 'o';
                    --n;
                } else {
                    // throw;
                    assert(j != w - 1);
                    a[w - j - 1][j] = 'o';
                    a[w - (j + 1) - 1][j + 1] = 'o';
                    n -= 2;

                    if (n == 0) {
                        if (curN + 2 != w * w) {
                            a[0][j - 1] = '.';
                            a[w - j][w - 1] = '.';
                            a[w - j - 1][j + 1] = 'o';
                            a[w - j - 2][j] = 'o';
                        } else {
                            a[w - j - 1][j] = '.';
                            a[w - (j + 1) - 1][j + 1] = '.';

                            printf("%d\n", w + 1);
                            std::vector<std::string> newAns(w + 1, std::string(w + 1, '.'));
                            for (int x = 0; x < w; ++x) {
                                for (int y = 0; y < w; ++y) {
                                    newAns[x + 1][y] = a[x][y];
                                }
                            }
                            newAns[0][0] = 'o';
                            newAns[w][w] = 'o';

                            for (int i = 0; i < w + 1; ++i) {
                                printf("%s\n", newAns[i].c_str());
                            }
                            return;
                        }
                        // a[j - 1][j] = 'o';
                        // a[w - j][j + 1] = 'o';
                    }
                    // assert(n != 0);
                    // if (n == 0) {
                    //     std::cout << curN << ' ';
                    // }
                }
            }

            assert(n % 2 == 0);

            int len = w - j - 1;
            if (2 * len > n) {
                len = n / 2;
            }

            for (int i = 0; i < len; ++i) {
                a[w - j - 1 - i - 1][j] = 'o';
                a[w - j - 1][j + i + 1] = 'o';
                n -= 2;
            }
        }
    // }

    printf("%d\n", w);
    for (int i = 0; i < w; ++i) {
        printf("%s\n", a[i].c_str());
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