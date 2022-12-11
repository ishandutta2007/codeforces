#include <cstdio>

int occ[26];
char s[28];
char ans[2][15] = {{ 0 }};

int main()
{
    for (int i = 0; i < 26; ++i) occ[i] = -1;
    char ch;
    int p1 = -1, p2 = -1;
    for (int i = 0; i < 27; ++i) {
        s[i] = getchar(); ch = s[i] - 'A';
        if (occ[ch] == -1) occ[ch] = i;
        else { p1 = occ[ch]; p2 = i; }
    }

    if (p1 + 1 == p2) { puts("Impossible"); return 0; }
    int delta = p2 - p1 - 1;
    int p1_pos = 12 - delta / 2;
    for (; p1_pos < 13; ++p1_pos, ++p1) ans[0][p1_pos] = s[p1];
    for (--p1; p1_pos >= 0; --p1_pos, p1 = (p1 + 1) % 27)
        if (p1 != p2) ans[1][p1_pos] = s[p1]; else ++p1_pos;
    for (p1 = (p1 + 26) % 27; p1_pos < 12 - delta / 2; ++p1_pos, p1 = (p1 + 1) % 27)
        ans[0][p1_pos] = s[p1];

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 13; ++j) putchar(ans[i][j] ? ans[i][j] : '-');
        putchar('\n');
    }

    return 0;
}