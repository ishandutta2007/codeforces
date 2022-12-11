#include <cstdio>
static const int MAXN = 104;

int n;
char s[MAXN];
int ct;
int a[MAXN];

int main()
{
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i) s[i] = getchar();

    ct = 0;
    for (int i = 0, j; i < n; i = j) {
        while (i < n && s[i] == 'W') ++i;
        if (i == n) break;
        j = i;
        while (j < n && s[j] == 'B') ++j;
        a[ct++] = j - i;
    }

    printf("%d\n", ct);
    for (int i = 0; i < ct; ++i) printf("%d%c", a[i], i == ct - 1 ? '\n' : ' ');

    return 0;
}