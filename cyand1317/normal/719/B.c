#include <stdio.h>
#define MAXN 100004

int n;
char s[MAXN];

int check(char start)
{
    int chg[2] = { 0, 0 };
    int i;
    for (i = 0; i < n; ++i) {
        if ((i & 1) ^ (s[i] == start)) ++chg[i & 1];
    }
    return (chg[0] > chg[1] ? chg[0] : chg[1]);
}

int main()
{
    scanf("%d", &n); getchar();
    int i;
    for (i = 0; i < n; ++i) s[i] = getchar();

    int ans1 = check('r'), ans2 = check('b');
    printf("%d\n", ans1 < ans2 ? ans1 : ans2);

    return 0;
}