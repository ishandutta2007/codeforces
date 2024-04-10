#include <cstdio>
char s[256];

int main()
{
    scanf("%*d");
    int ans = 0;
    int cur;
    while (scanf("%s", s) == 1) {
        cur = 0;
        for (int i = 0; s[i] != '\0'; ++i)
            if (s[i] >= 'A' && s[i] <= 'Z') ++cur;
        if (ans < cur) ans = cur;
    }
    printf("%d\n", ans);
    return 0;
}