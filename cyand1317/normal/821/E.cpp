#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long int64;
static const int MAXN = 102;
static const int MAXC = 17;
static const int MODULUS = 1e9 + 7;
#define _  %  MODULUS
#define __ %= MODULUS

struct mat {
    int64 f[MAXC][MAXC];
    mat() { memset(f, 0, sizeof f); }
    mat(int id) { memset(f, 0, sizeof f); for (int i = 0; i < MAXC; ++i) f[i][i] = id; }

    inline void operator *= (const mat &other) {
        int64 g[MAXC][MAXC];
        for (int i = 0; i < MAXC; ++i)
            for (int j = 0; j < MAXC; ++j) {
                g[i][j] = 0;
                for (int k = 0; k < MAXC; ++k)
                    (g[i][j] += f[i][k] * other.f[k][j])__;
            }
        memcpy(f, g, sizeof f);
    }
    inline void operator ^= (int64 exp) {
        mat ans(1);
        for (; exp; exp >>= 1, *this *= *this) if (exp & 1) ans *= *this;
        memcpy(this, &ans, sizeof *this);
    }
};

int n;
int64 k;

int64 l[MAXN], r[MAXN];
int c[MAXN];

inline mat ways(int64 l, int c)
{
    mat m;
    for (int i = 0; i <= c; ++i) {
        m.f[i][i] = 1;
        if (i > 0) m.f[i][i - 1] = 1;
        if (i < c) m.f[i][i + 1] = 1;
    }
    m ^= l;
    return m;
}

int main()
{
    scanf("%d%I64d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%I64d%I64d%d", &l[i], &r[i], &c[i]);

    r[n - 1] = std::min(r[n - 1], k);

    mat ans;
    ans.f[0][0] = 1;
    for (int i = 0; i < n; ++i) {
        ans *= ways(r[i] - l[i], c[i]);
        for (int j = c[i] + 1; j < MAXC; ++j) ans.f[0][j] = 0;
    }

    printf("%I64d\n", ans.f[0][0]);
    return 0;
}