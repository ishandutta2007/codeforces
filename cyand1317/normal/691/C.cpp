#include <cstdio>
static const int MAXN = 1e6 + 5;

int n;
char s[MAXN];

inline bool valid_in_num(char c)
{
    return c == '.' || (c >= '0' && c <= '9');
}
int main()
{
    int decpt_pos = -1;
    n = 0;
    while (valid_in_num(s[n] = getchar())) {
        if (s[n] == '.') decpt_pos = n;
        ++n;
    }
    if (decpt_pos == -1) { s[n] = '.'; decpt_pos = n++; }

    int i;
    int exp = decpt_pos - 1, first_dg, last_dg;
    for (i = 0; i < n; ++i)
        if (s[i] != '.' && s[i] != '0') break;
        else if (s[i] != '.') --exp;
    first_dg = i;
    for (i = n - 1; i >= first_dg; --i)
        if (s[i] != '.' && s[i] != '0') break;
    last_dg = i;

    if (first_dg == n) { puts("0"); return 0; }
    putchar(s[first_dg]);
    if (first_dg != last_dg) {
        putchar('.');
        for (i = first_dg + 1; i <= last_dg; ++i)
            if (s[i] != '.') putchar(s[i]);
    }
    if (exp != 0) printf("E%d", exp);
    putchar('\n');
    return 0;
}