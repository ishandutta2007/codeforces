#include <stdio.h>
#define MAXN 200003
char s[MAXN], t[MAXN];
int n;

unsigned char equivalent(int i, int j, int len)
{
    int x;
    if (len & 1) {
        for (x = 0; x < len; ++x)
            if (s[i + x] != t[j + x]) return 0;
        return 1;
    } else {
        return
            equivalent(i, j, len / 2) && equivalent(i + len / 2, j + len / 2, len / 2) ||
            equivalent(i, j + len / 2, len / 2) && equivalent(i + len / 2, j, len / 2);
    }
}

int main()
{
    n = -1;
    while ((s[++n] = getchar()) != '\n');
    int i;
    for (i = 0; i < n; ++i) t[i] = getchar();
    puts(equivalent(0, 0, n) ? "YES" : "NO");
    return 0;
}