#include <cstdio>
#include <cstring>
typedef long long int64;
static const int MAXN = 102;
static const int MODULUS = 1e9 + 7;
#define _  %  MODULUS
#define __ %= MODULUS
static const int INV2 = (MODULUS + 1) / 2;

int n;
char s[MAXN];

int main()
{
    scanf("%s", s);
    n = strlen(s);

    int64 ans = 0;
    int64 mul = 1;
    for (int i = 0; i < n; ++i) (mul *= 4)__;
    for (int i = 0; i < n; ++i) {
        (mul *= INV2)__;
        if (s[i] == '1') ans += mul;
    }

    printf("%I64d\n", (ans _) * INV2 _);
    return 0;
}