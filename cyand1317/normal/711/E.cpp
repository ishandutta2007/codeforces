#include <cstdio>
typedef long long int64;
static const int MODULUS = 1e6 + 3;
#define _ % MODULUS

int64 n, k;

inline int64 fpow(int64 base, int64 exp) {
    int64 ans = 1;
    for (; exp; exp >>= 1) {
        if (exp & 1) ans = (ans * base)_;
        base = (base * base)_;
    }
    return ans;
}
inline int64 inv(int64 x) {
    return fpow(x, MODULUS - 2);
}

int main()
{
    scanf("%I64d%I64d", &n, &k);
    if (8 * sizeof(k) - __builtin_clzll(k - 1) > n) {
        puts("1 1"); return 0;
    }

    int64 num = 1, deno = fpow(fpow(2, k - 1), n);
    if (k - 1 >= MODULUS) {
        num = 0;
    } else {
        int64 p = fpow(2, n);
        for (int i = 1; i <= k - 1; ++i)
            num = (num * (p - i + MODULUS))_;
    }
    int64 div_pow2 = (k - 1) - __builtin_popcountll(k - 1);
    div_pow2 = inv(fpow(2, div_pow2));
    num = (num * div_pow2)_;
    deno = (deno * div_pow2)_;
    num = (deno - num + MODULUS)_;

    printf("%I64d %I64d\n", num, deno);

    return 0;
}