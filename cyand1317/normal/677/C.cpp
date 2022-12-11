#include <cstdio>
#include <cstring>
typedef long long int64;
static const int MAXN = 100007;
static const int MODULUS = 1e9 + 7;
static const char digits[65] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_";
static int val[128];

int main()
{
    int64 ans = 1;
    char ch; int t;

    memset(val, -1, sizeof val);
    for (int i = 0; i < 64; ++i) val[digits[i]] = i;

    while ((t = val[ch = getchar()]) != -1) {
        for (int i = 0; i < 6; ++i)
            if (((t >> i) & 1) == 0) ans = (ans * 3) % MODULUS;
    }

    printf("%I64d\n", ans);
    return 0;
}