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
const int MOD = 998244353;

int add(int a, int b, int mod = MOD) {
    if (a + b >= mod) {
        return a + b - mod;
    }
    return a + b;
}

int sub(int a, int b, int mod = MOD) {
    if (a - b < 0) {
        return a - b + mod;
    }
    return a - b;
}

int mul(int a, int b, int mod = MOD) {
    return (int)(1ll * a * b % mod);
}

int binpow(int a, int n, int mod = MOD) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        return binpow(mul(a, a, mod), n / 2, mod);
    } else {
        return mul(binpow(a, n - 1, mod), a, mod);
    }
}

int rev(int a, int mod = MOD) {
    return binpow(a, mod - 2, mod);
}

const int N = 1 << 20;
const int LG = 20;

int w[N + 100];
int revMask[N + 100];

void FFTinit() {
    int w1 = 2;
    while (true) {
        int x = w1;
        for (int i = 0; i < LG - 1; ++i) {
            x = mul(x, x);
        }
        if (x == MOD - 1) {
            break;
        }
        ++w1;
    }

    w[0] = 1;
    w[1] = w1;
    for (int i = 2; i < N; ++i) {
        w[i] = mul(w[i - 1], w1);
    }
    for (int i = 1; i < N; ++i) {
        revMask[i] = (revMask[i >> 1] >> 1) ^ ((i & 1) << (LG - 1));
    }
}

// 2^k > maxDeg (20 max)
void FFT(int* A, int k) {
    int n = 1 << k;

    for (int i = 0; i < n; ++i) {
        int p = revMask[i] >> (LG - k);
        if (i < p) {
            std::swap(A[i], A[p]);
        }
    }

    for (int l = 0; l < k; ++l) {
        int len = 1 << l;
        for (int i = 0; i < n; i += len * 2) {
            for (int j = 0; j < len; ++j) {
                int x = A[i + j];
                int y = mul(A[i + j + len], w[j << (LG - 1 - l)]);

                A[i + j] = add(x, y);
                A[i + j + len] = sub(x, y);
            }
        }
    }
}

int A[N + 100], B[N + 100];

std::vector<int> multiply(std::vector<int>& a, std::vector<int>& b, int k) {
    int n = 1 << k;

    for (int i = 0; i < n; ++i) {
        if (i < (int)a.size()) {
            A[i] = a[i];
        } else {
            A[i] = 0;
        }

        if (i < (int)b.size()) {
            B[i] = b[i];
        } else {
            B[i] = 0;
        }
    }

    FFT(A, k);
    FFT(B, k);

    for (int i = 0; i < n; ++i) {
        A[i] = mul(A[i], B[i]);
    }

    FFT(A, k);

    std::reverse(A + 1, A + n);
    int rn = rev(n);
    for (int i = 0; i < n; ++i) {
        A[i] = mul(A[i], rn);
    }

    std::vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = A[i];
    }

    while (res.size() > 1 && res.back() == 0) {
        res.pop_back();
    }

    return res;
}

int f[N + 100], rf[N + 100];
std::vector<int> poly[N + 100];

void precalc() {
    f[0] = 1;
    rf[0] = 1;

    for (int i = 1; i < N + 100; ++i) {
        f[i] = mul(f[i - 1], i);
        rf[i] = rev(f[i]);
    }
}

int C(int n, int k) {
    return mul(f[n], mul(rf[k], rf[n - k]));
}

void run() {
    FFTinit();
    precalc();

    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);

    if (a == 0 || b == 0) {
        printf("0\n");
        return;
    }

    if (n == 1) {
        printf("1\n");
        return;
    }

    std::set<std::pair<int, int>> setik;
    for (int i = 0; i < n - 1; ++i) {
        poly[i] = std::vector<int>(2);
        poly[i][0] = i;
        poly[i][1] = 1;
        setik.insert(std::make_pair(2, i));
    }

    int cur = n - 1;
    while (setik.size() > 1) {
        int i1 = setik.begin()->second;
        setik.erase(setik.begin());
        int i2 = setik.begin()->second;
        setik.erase(setik.begin());

        int pp = 0;
        while ((1 << pp) < (int)poly[i1].size() + (int)poly[i2].size()) {
            ++pp;
        }

        poly[cur] = multiply(poly[i1], poly[i2], pp);
        setik.insert(std::make_pair(poly[cur].size(), cur));
        ++cur;
    }

    // for (auto i : poly[cur - 1]) {
    //     printf("%d ", i);
    // }
    // printf("\n");

    int ans = (a + b - 2 < (int)poly[cur - 1].size()) ? poly[cur - 1][a + b - 2] : 0;
    // debug(ans);
    ans = mul(ans, C(a + b - 2, a - 1));

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