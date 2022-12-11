#include <cstdio>
typedef long long int64;

int64 n, l, r;
int bits;

inline bool query(int64 pos) {
    return (n >> (bits - __builtin_ctzll(pos) - 1)) & 1;
}

int main()
{
    scanf("%I64d%I64d%I64d", &n, &l, &r);
    bits = 8 * sizeof(int64) - __builtin_clzll(n);
    int ans = 0;
    for (; l <= r; ++l) ans += query(l);
    printf("%d\n", ans);
    return 0;
}