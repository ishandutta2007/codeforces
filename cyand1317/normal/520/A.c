#include <stdio.h>

int main()
{
    unsigned short c[26] = {0};
    int n;
    scanf("%d\n", &n);
    while (n--) {
        char ch = getchar();
        if (ch >= 'a') c[ch - 'a'] = 1;
        else c[ch - 'A'] = 1;
    }
    for (n = 0; n < 26; ++n)
        if (!c[n]) break;
    puts(n == 26 ? "YES" : "NO");
    return 0;
}