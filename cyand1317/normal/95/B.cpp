#include <cstdio>
static const int MAXLEN = 100008;
template <typename T> inline T abs(const T x) { return x < 0 ? -x : x; }

int n;
char _s[MAXLEN], *s;
char t[MAXLEN] = { 0 };

bool calc(int rem4, int rem7)
{
    if (!rem4 && !rem7) return true;
    int u = n - rem4 - rem7;
    if (rem4 > 0) {
        t[u] = 4;
        if (s[u] < 4) {
            --rem4;
            for (int i = 0; i < rem4; ++i) t[1 + u + i] = 4;
            for (int i = 0; i < rem7; ++i) t[1 + u + i + rem4] = 7;
            return true;
        } else if (s[u] == 4 && calc(rem4 - 1, rem7)) return true;
    }
    if (rem7 > 0) {
        t[u] = 7;
        if (s[u] < 7) {
            --rem7;
            for (int i = 0; i < rem4; ++i) t[1 + u + i] = 4;
            for (int i = 0; i < rem7; ++i) t[1 + u + i + rem4] = 7;
            return true;
        } else if (s[u] == 7 && calc(rem4, rem7 - 1)) return true;
    }
    return false;
}

int main()
{
    n = 0;
    while ((_s[n + 2] = getchar() - '0') >= 0 && _s[n + 2] <= 9) ++n;

    if (n % 2 != 0) {
        ++n;
        for (int i = 0; i < n / 2; ++i) { t[i] = 4; t[i + n / 2] = 7; }
    } else {
        s = _s + 2;
        if (!calc(n / 2, n / 2)) {
            s = _s; n += 2;
            calc(n / 2, n / 2);
        }
    }
    for (int i = 0; t[i]; ++i) putchar('0' + t[i]);

    return 0;
}