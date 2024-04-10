#include <stdio.h>
#define MAXN 200004

int main()
{
    int n, i, j, k, hamming = 0;
    char s[MAXN], t[MAXN];
    int pair[26][26];
    unsigned char unmatched[26] = {0};

    scanf("%d\n", &n);
    for (i = 0; i < 26; ++i)
        for (j = 0; j < 26; ++j) pair[i][j] = -1;
    for (i = 0; i < n; ++i) s[i] = getchar(); getchar();
    for (i = 0; i < n; ++i) {
        t[i] = getchar();
        pair[s[i] - 'a'][t[i] - 'a'] = i;
        if (s[i] != t[i]) {
            ++hamming; unmatched[s[i] - 'a'] = 1;
        }
    }

    int p1 = -1, p2 = -1;
    for (i = 0; i < 26; ++i)
        for (j = 0; j < 26; ++j) if (i != j && pair[i][j] != -1 && pair[j][i] != -1) {
            hamming -= 2;
            p1 = pair[i][j]; p2 = pair[j][i];
            goto found; // This won't mess up the code, I think...
        }
    for (i = 0; i < 26; ++i)
        for (j = 0; j < 26; ++j) if (i != j && pair[i][j] != -1 && unmatched[j])
            for (k = 0; k < 26; ++k) if (j != k && pair[j][k] != -1) {
                --hamming;
                p1 = pair[i][j]; p2 = pair[j][k];
                goto found;
            }
    p1 = p2 = -2;   // Will be added by one

found:
    printf("%d\n%d %d\n", hamming, p1 + 1, p2 + 1);
    return 0;
}