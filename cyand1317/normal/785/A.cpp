#include <cstdio>

int main()
{
    int n; scanf("%d", &n);
    char s[64];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        switch (s[0]) {
            case 'T': ans += 4; break;
            case 'C': ans += 6; break;
            case 'O': ans += 8; break;  // TCO??
            case 'D': ans += 12; break;
            case 'I': ans += 20; break;
        }
    }
    printf("%d\n", ans);
    return 0;
}