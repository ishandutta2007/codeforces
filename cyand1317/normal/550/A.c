#include <stdio.h>
#define MAXN 100003

int main()
{
    char s[MAXN];
    int n = -1;
    while ((s[++n] = getchar()) != '\n');

    int any = 0, ab = 0, ba = 0;
    int i, last1 = '\0', last2 = '\0', last_any = 0;
    for (i = 0; i < n; last2 = last1, last1 = s[i++]) {
        if (last_any) --last_any;
        switch (s[i]) {
            case 'A':
                if (!last_any && last2 == 'A' && last1 == 'B') { --ab; ++any; last_any = 3; }
                else if (last_any <= 1 && last1 == 'B') ++ba;
                break;
            case 'B':
                if (!last_any && last2 == 'B' && last1 == 'A') { --ba; ++any; last_any = 3; }
                else if (last_any <= 1 && last1 == 'A') ++ab;
                break;
            default: break;
        }
    }
    puts(any >= 2 || (!!any) + (!!ab) + (!!ba) >= 2 ? "YES" : "NO");
    return 0;
}