#include <cstdio>
static const int MAXLEN = 1006;

int ns = 0, nt = 0;
char s[MAXLEN], t[MAXLEN];
char swapped[26];

int main()
{
    while ((s[ns] = getchar()) >= 'a' && s[ns] <= 'z') ++ns;
    while ((t[nt] = getchar()) >= 'a' && t[nt] <= 'z') ++nt;

    for (int i = 0; i < 26; ++i) swapped[i] = -1;
    int swap_ct = 0;
    for (int i = 0; i < ns; ++i) {
        if (swapped[s[i] - 'a'] == -1 && swapped[t[i] - 'a'] == -1) {   // T^T...
            swapped[s[i] - 'a'] = t[i];
            swapped[t[i] - 'a'] = s[i];
            if (s[i] != t[i]) ++swap_ct;
        } else if (swapped[s[i] - 'a'] != t[i]) { puts("-1"); return 0; }
    }

    printf("%d\n", swap_ct);
    for (int i = 0; i < 26; ++i) if (swapped[i] != -1 && swapped[i] < i + 'a') {
        printf("%c %c\n", i + 'a', swapped[i]);
    }

    return 0;
}