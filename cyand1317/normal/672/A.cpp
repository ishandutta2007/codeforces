#include <cstdio>
static const int NUM_CNT = 404;
static const int TOT_LEN = 4040;
char _s[TOT_LEN];

int main()
{
    char *s = _s;
    for (int i = 1; i < NUM_CNT; ++i) {
        sprintf(s, "%d", i);
        while (*s) ++s;
    }
    int n;
    scanf("%d", &n);
    putchar(_s[n - 1]);
    return 0;
}