#include <cstdio>
#include <cstring>
static const int MAXN = 404;
static const int MAXL = 42;

static int n;
static char s[MAXL];
static char t[MAXN][MAXL];

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        int len = strlen(s), ptr = 0;
        for (int j = 0; j < len; ++j) {
            if (s[j] == 'u') {
                t[i][ptr++] = 'o';
                t[i][ptr++] = 'o';
            } else if (j < len - 1 && s[j] == 'k' && s[j + 1] == 'h') {
                while (ptr > 0 && t[i][ptr - 1] == 'k') --ptr;
                t[i][ptr++] = 'h'; ++j;
            } else {
                t[i][ptr++] = s[j];
            }
        }
        t[i][ptr] = '\0';
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        bool valid = true;
        for (int j = 0; j < i; ++j)
            if (strcmp(t[i], t[j]) == 0) { valid = false; break; }
        if (valid) ++ans;
    }
    printf("%d\n", ans);

    return 0;
}