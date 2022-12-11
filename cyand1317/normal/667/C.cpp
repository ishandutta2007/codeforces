#include <cstdio>
static const int MAXN = 10006;
static const int ALPHA = 28;

int n;
char s[MAXN] = { '\0' };
bool valid_suf[MAXN][2] = {{ false }};
bool suffix_exists[ALPHA][ALPHA][ALPHA] = {{{ false }}};

inline bool is_alpha(const char c) { return c >= 'a' && c <= 'z'; }
inline bool substr_eql(const int i, const int j, int len) {
    while (len--) if (s[i + len] != s[j + len]) return false;
    return true;
}
inline void add_suffix(const int pos, const int len) {
    if (len == 2) suffix_exists[s[pos] - 'a' + 1][s[pos + 1] - 'a' + 1][0] = true;
    else suffix_exists[s[pos] - 'a' + 1][s[pos + 1] - 'a' + 1][s[pos + 2] - 'a' + 1] = true;
}
int main()
{
    n = -1; while (is_alpha(s[++n] = getchar()));

    valid_suf[n - 2][0] = valid_suf[n - 3][1] =
    valid_suf[n][0] = valid_suf[n][1] = true;
    for (int i = 0; i < 5; ++i) valid_suf[i][0] = valid_suf[i][1] = false;
    for (int i = n - 4; i >= 5; --i) {
        valid_suf[i][0] =
            (valid_suf[i + 2][0] && !substr_eql(i, i + 2, 2)) ||
            (valid_suf[i + 2][1]);
        valid_suf[i][1] =
            (valid_suf[i + 3][1] && !substr_eql(i, i + 3, 3)) ||
            (valid_suf[i + 3][0]);
    }
    for (int i = 0; i < n; ++i) {
        if (valid_suf[i][0]) add_suffix(i, 2);
        if (valid_suf[i][1])add_suffix(i, 3);
    }
    int suffix_ct = 0;
    for (int i = 1; i < ALPHA; ++i)
        for (int j = 1; j < ALPHA; ++j)
            for (int k = 0; k < ALPHA; ++k) suffix_ct += suffix_exists[i][j][k];
    printf("%d\n", suffix_ct);
    for (int i = 1; i < ALPHA; ++i)
        for (int j = 1; j < ALPHA; ++j)
            for (int k = 0; k < ALPHA; ++k) if (suffix_exists[i][j][k]) {
                putchar(i + 'a' - 1);
                putchar(j + 'a' - 1);
                if (k) putchar(k + 'a' - 1);
                putchar('\n');
            }
    return 0;
}