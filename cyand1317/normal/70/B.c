#include <stdio.h>
#define MAXLEN 10006

int n, len = 0;
char s[MAXLEN];
int s_len[MAXLEN], s_ct = 0;

unsigned int valid(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ||
        ch == ' ' || ch == '.' || ch == '?' || ch == '!';
}
int main()
{
    scanf("%d", &n); getchar();
    while (valid(s[len] = getchar())) ++len;

    int i;
    for (i = 0; i < len; ++i) {
        ++s_len[s_ct];
        if (s[i] == '.' || s[i] == '?' || s[i] == '!') { ++s_ct; ++i; }
    }
    if (s_len[0] > n) { puts("Impossible"); return 0; }
    int ans = 1, accum = s_len[0];
    for (i = 1; i < s_ct; ++i) {
        if (accum + s_len[i] + 1 > n) {
            if (s_len[i] > n) { puts("Impossible"); return 0; }
            ++ans; accum = s_len[i];
        } else {
            accum += s_len[i] + 1;
        }
    }
    printf("%d\n", ans);

    return 0;
}