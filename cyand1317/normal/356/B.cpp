#include <cstdio>
#include <cstring>
typedef long long int64;
static const int MAXL = 1e6 + 5;
static const int ALPH = 26;
template <typename T> inline T gcd(const T a, const T b) { return (b == 0) ? a : gcd(b, a % b); }

int64 n, m;
char s[MAXL], t[MAXL];
int sl, tl;

int sct[MAXL][ALPH] = {{ 0 }}, tct[MAXL][ALPH] = {{ 0 }};

int main()
{
    scanf("%I64d%I64d", &n, &m);
    scanf("%s", s); sl = strlen(s);
    scanf("%s", t); tl = strlen(t);

    int g = gcd(sl, tl);

    for (int i = 0; i < sl; ++i) ++sct[i % g][s[i] - 'a'];
    for (int i = 0; i < tl; ++i) ++tct[i % g][t[i] - 'a'];

    int64 ans = 0;
    for (int i = 0; i < g; ++i) {
        for (int j = 0; j < ALPH; ++j)
            ans += (int64)sct[i][j] * (tl / g - tct[i][j]);
    }

    printf("%I64d\n", ans * (n / (tl / g)));
    return 0;
}