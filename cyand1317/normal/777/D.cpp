#include <cstdio>
static const int MAXN = 500004;
static const int MAXL = 500014;

int n, head[MAXN], len[MAXN], cut[MAXN];
char s[MAXL];

int main()
{
    scanf("%d", &n); getchar();
    char ch;
    for (int i = 0; i < n; ++i) {
        getchar();
        head[i] = (i == 0 ? 0 : head[i - 1] + len[i - 1]);
        len[i] = 0;
        while ((ch = getchar()) != '\n') {
            s[head[i] + (len[i]++)] = ch;
        }
    }

    cut[n - 1] = 0;
    for (int i = n - 2; i >= 0; --i) {
        cut[i] = -1;    // not determined
        for (int j = 0; j < len[i]; ++j)
            if (j < len[i + 1] - cut[i + 1] && s[head[i] + j] < s[head[i + 1] + j]) {
                cut[i] = 0; break;
            } else if (j >= len[i + 1] - cut[i + 1] || s[head[i] + j] > s[head[i + 1] + j]) {
                cut[i] = len[i] - j; break;
            }
        if (cut[i] == -1) cut[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        putchar('#');
        for (int j = 0; j < len[i] - cut[i]; ++j) putchar(s[head[i] + j]);
        putchar('\n');
    }
    return 0;
}