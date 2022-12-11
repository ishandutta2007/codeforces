#include <stdio.h>
#define MAXN 107
#define TRUE  1
#define FALSE 0

int n, d;
int ans = 0, cur = 0, flag;

int main()
{
    scanf("%d%d", &n, &d);

    int i;
    do {
        flag = FALSE;
        getchar();
        for (i = 0; i < n; ++i) {
            flag |= (getchar() == '0');
        }
        if (flag) {
            if (ans < ++cur) ans = cur;
        } else {
            cur = 0;
        }
    } while (--d);
    printf("%d\n", ans);
    return 0;
}