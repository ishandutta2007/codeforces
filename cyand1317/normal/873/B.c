#include <stdio.h>
#define MAXN    100004

int n;
char s[MAXN];
int last[MAXN * 2];

int main()
{
    scanf("%d", &n);
    scanf("%s", s);

    int i, x = MAXN;
    int ans = 0;
    for (i = 0; i < MAXN * 2; ++i) last[i] = -2;
    last[x] = -1;
    for (i = 0; i < n; ++i) {
        x += (s[i] == '0' ? -1 : +1);
        if (last[x] != -2) {
            if (ans < i - last[x])
                ans = i - last[x];
        } else {
            last[x] = i;
        }
    }
    printf("%d\n", ans);

    return 0;
}