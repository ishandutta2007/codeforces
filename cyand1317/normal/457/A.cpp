#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using std::swap;
static const int MAXN = 100005;
template <typename T> inline short sign(const T x) { return x > 0 ? +1 : (x < 0 ? -1 : 0); }

int s[MAXN], t[MAXN];

inline void platinum_get(int s[MAXN])
{
    static char str[MAXN];
    gets(str);
    int len = strlen(str);
    memset(s, 0, sizeof(int) * MAXN);
    for (int i = 0; i < len; ++i) s[len - i - 1] = str[i] - '0';
}

inline short platinum_cmp(int *_s, int *_t)
{
    int *s = _s, *t = _t;
    int msb = MAXN - 1;
    while (msb >= 0 && s[msb] == t[msb]) --msb;
    if (msb < 0) return 0;

    for (; msb >= 2; --msb) if (s[msb] != t[msb]) {
        if (!s[msb]) swap(s, t);
        s[msb] = 0; ++s[msb - 1]; ++s[msb - 2];
        s[msb - 1] -= t[msb - 1]; s[msb - 2] -= t[msb - 2];
        t[msb - 1] = t[msb - 2] = 0;
        if (s[msb - 1] >= 2 || s[msb - 2] >= 2) return (_s == s ? +1 : -1);
    }
    static const double Q = (sqrt(5) + 1) / 2;
    return sign(Q * (s[1] - t[1]) + (s[0] - t[0])) * (_s == s ? +1 : -1);
}

int main()
{
    platinum_get(s);
    platinum_get(t);

    switch (platinum_cmp(s, t)) {
        case +1: puts(">"); break;
        case  0: puts("="); break;
        case -1: puts("<"); break;
    }
    return 0;
}