#include <cstdio>
#include <algorithm>
typedef long long int64;
static const int MAXM = 1e9 + 7;
static const int MAXN = 1e5 + 4;

int m, n;
int a[MAXN];
#define _ % m
#define __ %= m

inline int fpow(int base, int exp) {
    int64 ans = 1;
    for (; exp; exp >>= 1) { if (exp & 1) (ans *= base)__; base = ((int64)base * base)_; }
    return ans;
}
inline int inv(int x) { return fpow(x, m - 2); }

inline bool check(int x, int d) {
    static int b[MAXN];
    b[0] = x;
    for (int i = 1; i < n; ++i) b[i] = (b[i - 1] + d)_;
    std::sort(b, b + n);
    for (int i = 0; i < n; ++i) if (b[i] != a[i]) return false;
    return true;
}

// Arithmetic sequence
inline int as_sqr_sum(int x, int d) {
    static int inv_6 = -1;
    if (inv_6 == -1) inv_6 = inv(6);
    return ((int64)n * x _ * x _ + (int64)(n - 1) * n _ * d _ * x _ +
        (int64)d * d _ * (n - 1)_ * n _ * (n + n - 1)_ * inv_6 _)_;
}
inline int as_cbc_sum(int x, int d) {
    static int inv_2 = -1;
    if (inv_2 == -1) inv_2 = inv(2);
    return ((int64)n * x _ * x _ * x _ +
        (int64)(n - 1) * (n - 1)_ * n _ * n _ * d _ * d _ * d _ * inv_2 _ * inv_2 _ +
        (int64)d * d _ * x _ * (n - 1)_ * n _ * (n + n - 1)_ * inv_2 _ +
        (int64)d * x _ * x _ * (n - 1)_ * n _ * inv_2 _ * 3 _)_;
}

int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    if (n == 1) { printf("%d 0\n", a[0]); return 0; }

    std::sort(a, a + n);
    int sum = 0;
    int sqr_sum = 0, cbc_sum = 0;
    for (int i = 0; i < n; ++i) {
        (sum += a[i])__;
        sqr_sum = ((int64)a[i] * a[i] + sqr_sum)_;
        cbc_sum = ((int64)a[i] * a[i]_ * a[i] + cbc_sum)_;
    }

    int inv_2 = inv(2), inv_n = inv(n);
    for (int j = 1; j < n; ++j) {
        int d = (a[0] - a[j] + m)_;
        int x = (sum - (int64)n * (n - 1)_ * inv_2 _ * d _ + m)_ * inv_n _;
        if (*std::lower_bound(a, a + n, x) == x &&
            as_sqr_sum(x, d) == sqr_sum &&
            as_cbc_sum(x, d) == cbc_sum && check(x, d))
        {
            printf("%d %d\n", x, d); return 0;
        }
    }

    puts("-1");
    return 0;
}