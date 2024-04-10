#include <cstdio>
#include <cstring>
typedef long long int64;
static const int MAXDG = 14;
static const int64 UPPER_BD = (1LL << (MAXDG * 4)) - 1;

int k, t;
int64 binom[MAXDG + 1][MAXDG + 1] = {{ 0 }};

inline void init_binomials()
{
    for (int i = 0; i <= MAXDG; ++i) {
        binom[i][0] = 1;
        for (int j = 1; j <= i; ++j) binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
    }
}

inline int64 freestyle(int digits, int *ct)
{
    static int64 f[MAXDG + 1], g[MAXDG + 1];
    memset(f, 0, sizeof f);
    f[0] = 1;
    for (int i = 0; i < 16; ++i) {
        memset(g, 0, sizeof g);
        if (t - ct[i] < 0) return 0;
        for (int j = 0; j <= t - ct[i]; ++j) {
            for (int k = digits; k >= 0; --k)
                if (k + j <= digits) g[k + j] += f[k] * binom[k + j][j];
        }
        for (int i = 0; i <= digits; ++i) f[i] = g[i];
    }
    return f[digits];
}

int64 count_less(int64 up)
{
    static int ct[16];
    static char hex[MAXDG + 1];
    for (int i = 0; i < 16; ++i) ct[i] = 0;
    sprintf(hex, "%I64x", up);

    int64 ans = 0;
    int hex_len = strlen(hex), cur_dg;
    for (int i = 1; i < hex_len; ++i) {
        for (int dg = 1; dg < 16; ++dg) {
            ++ct[dg];
            ans += freestyle(i - 1, ct);
            --ct[dg];
        }
    }
    for (int i = 0; i < hex_len; ++i) {
        if (hex[i] >= '0' && hex[i] <= '9') cur_dg = hex[i] - '0'; else cur_dg = hex[i] - 'a' + 10;
        for (int dg = (i == 0 ? 1 : 0); dg < cur_dg; ++dg) {
            ++ct[dg];
            ans += freestyle(hex_len - i - 1, ct);
            --ct[dg];
        }
        ++ct[cur_dg];
    }

    return ans;
}

int main()
{
    init_binomials();
    scanf("%d%d", &k, &t);

    int64 lo = 0, hi = UPPER_BD, mid;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        if (count_less(mid) < k) lo = mid; else hi = mid;
    }

    printf("%I64x\n", lo);
    return 0;
}