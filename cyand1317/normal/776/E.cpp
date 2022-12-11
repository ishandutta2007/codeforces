#include <cstdio>
typedef long long int64;
#define MODULUS 1000000007

int64 n, k;

inline int64 totient(int64 x) {
    int64 ans = x;
    for (int64 i = 2; i * i <= x; ++i) if (x % i == 0) {
        ans /= i; ans *= (i - 1);
        do x /= i; while (x % i == 0);
    }
    if (x != 1) { ans /= x; ans *= (x - 1); }
    return ans;
}

int main()
{
    scanf("%I64d%I64d", &n, &k);
    for (int64 i = k; i >= 1 && n != 1; --i) {
        if (i % 2 != 0) n = totient(n);
    }
    printf("%I64d\n", n % MODULUS);
    return 0;
}