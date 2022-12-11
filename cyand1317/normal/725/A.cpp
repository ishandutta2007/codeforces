#include <cstdio>
static const int MAXN = 200005;

int n;
char s[MAXN];

int main()
{
    scanf("%d", &n); getchar();
    for (int i = 0; i < n; ++i) s[i] = getchar();

    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (s[i] == '<') ++ans; else break;
    for (int i = n - 1; i >= 0; --i)
        if (s[i] == '>') ++ans; else break;

    printf("%d\n", ans);
    return 0;
}