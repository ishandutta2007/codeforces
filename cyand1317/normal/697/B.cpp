#include <cstdio>
static const int MAXLEN = 108;

char s[MAXLEN];
int b;

int main()
{
    s[0] = getchar();
    getchar();  // Decimal point
    int l = 0;
    while ((s[++l] = getchar()) != 'e') ;
    for (int i = l; i < MAXLEN; ++i) s[i] = '0';
    scanf("%d", &b);

    int p = 0, q = MAXLEN - 1;
    while (p < b && s[p] == '0') ++p;
    while (q > p && q > b && s[q] == '0') --q;
    for (int i = p; i <= q; ++i) {
        putchar(s[i]);
        if (i == b && i != q) putchar('.');
    }
    putchar('\n');

    return 0;
}