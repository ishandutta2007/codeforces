#include <cstdio>
typedef long long int64;
static const int MAXK = 1 << 17;
static const int LOGK = 17;
static const int MODULUS = 998244353;
static const int PRIMITIVE = 8996;
#define _ % MODULUS
#define __ %= MODULUS
template <typename T> inline void swap(T &a, T &b) { static T t; t = a; a = b; b = t; }

int n, k, real_k;
int f[3][MAXK] = {{ 0 }};

inline int fpow(int base, int exp)
{
    int64 ans = 1;
    for (; exp; exp >>= 1) { if (exp & 1) (ans *= base)__; base = (int64)base * base _; }
    return ans;
}

int bitrev[MAXK];
int root[2][LOGK];
inline void ntt(int n, int *a, int direction)
{
    int64 u, v, r, w;
    for (int i = 0; i < n; ++i) if (i < bitrev[i]) swap(a[i], a[bitrev[i]]);
    for (int i = 1; i <= n; i <<= 1)
        for (int j = 0; j < n; j += i) {
            r = root[direction == -1][__builtin_ctz(i)];
            w = 1;
            for (int k = j; k < j + (i >> 1); ++k) {
                u = a[k];
                v = ((int64)a[k + (i >> 1)] * w)_;
                a[k] = (u + v)_;
                a[k + (i >> 1)] = (u - v + MODULUS)_;
                w = (w * r)_;
            }
        }
}

inline void row_convolve(int n, int *ia, int *ib, int *c)
{
    for (int i = 0; i < n; ++i) c[i] = ((int64)ia[i] * ib[i])_;
    ntt(n, c, -1);
    int inv = fpow(n, MODULUS - 2);
    for (int i = 0; i < n; ++i) c[i] = ((int64)c[i] * inv)_;
}
inline void row_add(int n, int *a, int *b, int *c, int offset = 0)
{
    for (int i = 0; i < n; ++i) c[i] = a[i];
    for (int i = 0; i < n; ++i)
        if (i + offset >= 0 && i + offset < n) (c[i] += b[i + offset])__;
}

// f[n-2], f[n-1], f[n]  f[2n-2], f[2n-1], f[2n]
void f_double()
{
    static int t[5][MAXK];
    ntt(k, f[0], 1);
    ntt(k, f[1], 1);
    ntt(k, f[2], 1);
    row_convolve(k, f[0], f[0], t[0]);
    row_convolve(k, f[1], f[1], t[1]);
    row_convolve(k, f[2], f[2], t[2]);
    row_convolve(k, f[0], f[1], t[3]);
    row_convolve(k, f[1], f[2], t[4]);
    row_add(k, t[1], t[0], f[0], -1);
    row_add(k, t[4], t[3], f[1], -1);
    row_add(k, t[2], t[1], f[2], -1);
    for (int i = k / 2; i < k; ++i) f[0][i] = f[1][i] = f[2][i] = 0;
}
// f[n-2], f[n-1], f[n]  f[n-1], f[n], f[n+1]
void f_increment()
{
    for (int i = 0; i < k; ++i) { f[0][i] = f[1][i]; f[1][i] = f[2][i]; }
    for (int i = 0; i < k; ++i)
        f[2][i] = ((f[1][i] + f[1][i - 1])_ + f[0][i - 1])_;
    for (int i = k / 2; i < k; ++i) f[0][i] = f[1][i] = f[2][i] = 0;
}

void print(int row_idx)
{
    for (int i = 1; i <= real_k; ++i) printf("%d%c", f[row_idx][i], i == real_k ? '\n' : ' ');
}

int main()
{
    //for (int i = 2; i < MODULUS; ++i)
    //    if (fpow(i, MAXK) == 1) { printf("PRIMITIVE = %d\n", i); break; }

    scanf("%d%d", &n, &real_k);
    int sz = 8 * sizeof(int) - __builtin_clz(real_k) + 1;
    k = (1 << sz);
    for (int i = 0; i < k; ++i) bitrev[i] = (bitrev[i >> 1] >> 1) | ((i & 1) << (sz - 1));
    for (int i = 0; i < LOGK; ++i) {
        root[0][i] = fpow(PRIMITIVE, MAXK >> i);
        root[1][i] = fpow(PRIMITIVE, MAXK - (MAXK >> i));
    }

    f[0][0] = f[1][0] = f[1][1] = 1;
    for (int i = 0; i <= k; ++i)
        f[2][i] = ((f[1][i] + f[1][i - 1])_ + f[0][i - 1])_;

    if (n <= 2) print(n);
    else {
        unsigned int n_rev = 0;
        int bits = 0;
        for (; n; n >>= 1) n_rev = (n_rev << 1) | (n & 1), ++bits;
        n_rev >>= 1; --bits;    // remove leading bit 1
        if (n_rev & 1) f_increment();
        n_rev >>= 1; --bits;    // since we're starting with n=2
        for (; bits > 0; n_rev >>= 1, --bits) {
            f_double();
            if (n_rev & 1) f_increment();
        }
        print(2);
    }

    return 0;
}