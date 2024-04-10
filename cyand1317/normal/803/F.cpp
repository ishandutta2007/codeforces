#include <cstdio>
typedef long long int64;
static const int MAXN = 100005;
static const int MAXA = 100009;
static const int MODULUS = 1e9 + 7;
#define _  %  MODULUS
#define __ %= MODULUS

int n, a_i, ct[MAXA] = { 0 };
int pow2[MAXN];
int64 s[MAXA];

int main()
{
    pow2[0] = 1;
    for (int i = 1; i < MAXN; ++i) pow2[i] = (pow2[i - 1] + pow2[i - 1])_;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a_i);
        for (int j = 1; j * j <= a_i; ++j) if (a_i % j == 0) {
            ++ct[j];
            if (j * j != a_i) ++ct[a_i / j];
        }
    }

    for (int i = 1; i < MAXA; ++i) s[i] = (pow2[ct[i]] - 1 + MODULUS)_;
    for (int i = MAXA - 1; i >= 2; --i) if (s[i]) {
        for (int j = 1; j * j <= i; ++j) if (i % j == 0) {
            s[j] = (s[j] - s[i] + MODULUS)_;
            if (j != 1 && j * j != i) s[i / j] = (s[i / j] - s[i] + MODULUS)_;
        }
    }
    printf("%I64d\n", s[1]);

    return 0;
}