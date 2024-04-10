#include <stdio.h>

int main()
{
    int n, ans = 0;
    int key[26] = {0};
    scanf("%d\n", &n);
    while (--n) {
        int ch = getchar() - 'a';
        key[ch]++;
        ch = getchar() - 'A';
        if (key[ch]) key[ch]--; else ans++;
    }

    printf("%d\n", ans);
    return 0;
}