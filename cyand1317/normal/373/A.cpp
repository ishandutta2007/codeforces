#include <cstdio>

int k, t[4][4], ct[10] = { 0 };
char ch;

int main()
{
    scanf("%d", &k); getchar();
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j <= 4; ++j) switch (ch = getchar()) {
            case '.': case '\n': break;
            default: ++ct[ch - '0']; break;
        }
    for (int i = 1; i <= 9; ++i) if (ct[i] > 2 * k) { puts("NO"); return 0; }
    puts("YES");
    return 0;
}