#include <cstdio>
static const int MAXN = 105;

int n;
char s[MAXN];
int offset[4], count[4] = { 0 };

int main()
{
    for (n = 0; (s[n] = getchar()) != '\n'; ++n) ; s[n] = '\0';

    for (int i = 0; i < n; ++i) switch (s[i]) {
        case 'R': offset[i % 4] = 0; break;
        case 'B': offset[i % 4] = 1; break;
        case 'Y': offset[i % 4] = 2; break;
        case 'G': offset[i % 4] = 3; break;
        case '!': default: break;
    }
    for (int i = 0; i < n; ++i) if (s[i] == '!') ++count[offset[i % 4]];

    printf("%d %d %d %d\n", count[0], count[1], count[2], count[3]);
    return 0;
}