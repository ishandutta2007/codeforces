#include <cstdio>
static const int MAXLEN = 1e6 + 2;

int n, t;
int len = 0;
char s[MAXLEN] = { 0 };
int dec_pt = 0;

inline int is_4445()
{
    bool flag = false;
    for (int i = dec_pt; i < len; ++i) {
        if (s[i - 1] == '4' && s[i] >= '5' && s[i] <= '9') return i;
        else if (s[i] >= '5' && s[i] <= '9') return -1;
    }
    return -1;
}

int main()
{
    scanf("%d%d", &n, &t); getchar();
    while ((s[len] = getchar()) >= '0' && s[len] <= '9' || s[len] == '.') {
        if (s[len] == '.') dec_pt = len; else ++len;
    }
    n = len;

    int p = is_4445();
    if (p >= 0) {
        for (int i = p + 1; i < len; ++i) s[i] = 0;
        while (p >= dec_pt && t > 0 && s[p - 1] == '4') {
            --t; s[p] = 0; s[--p] = '5';
        }
    }
    if (t > 0) for (int i = dec_pt; i < len; ++i) if (s[i] >= '5' && s[i] <= '9') {
        s[i - 1]++;
        for (int j = i; j < len; ++j) s[i] = 0;
        break;
    }
    for (int i = len - 1; i > 0; --i) if (s[i] > '9') { s[i] -= 10; s[i - 1] += 1; }
    for (int i = len - 1; i >= dec_pt; --i) if (s[i] == '0') s[i] = 0; else break;
    printf("%d", s[0] - '0');
    for (int i = 1; i < dec_pt; ++i) putchar(s[i]);
    if (s[dec_pt] != 0) {
        putchar('.');
        for (int i = dec_pt; s[i] != 0; ++i) putchar(s[i]);
    }
    putchar('\n');

    return 0;
}