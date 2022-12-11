#include <cstdio>
#include <algorithm>
static const int MAXN = 5004;
static const int LOGN = 13;

static int n, k;
static char s[MAXN];
static bool v[1 << LOGN] = { false };

int main()
{
    for (n = 0; (s[n] = getchar()) >= 'a' && s[n] <= 'z'; ++n) ;
    k = 8 * sizeof(int) - __builtin_clz(n) - 1;

    for (int i = 0; i < n - (1 << k) + 1; ++i) {
        char c = 'z' + 1;
        for (int j = 0; j < (1 << k); ++j) if (!v[j]) c = std::min(c, s[i + j]);
        for (int j = 0; j < (1 << k); ++j) {
            v[j] |= (c < s[i + j]);
            for (int t = 0; t < k; ++t) v[j] &= v[j & ~(1 << t)];
        }
        putchar(c);
    }

    return 0;
}