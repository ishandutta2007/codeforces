#include <cstdio>
#include <cstring>
#include <algorithm>
static const int MAXN = 1e5 + 4;

int n, m;
char s[MAXN], t[MAXN];
int f[MAXN], g[MAXN];

int main()
{
    gets(s + 1); n = strlen(s + 1);
    gets(t + 1); m = strlen(t + 1);

    f[0] = -1;
    for (int i = 1; i <= m; ++i) {
        for (f[i] = std::min(f[i - 1] + 1, n); f[i] < n && s[f[i] + 1] != t[i]; ++f[i]) ;
    }
    std::reverse(s + 1, s + n + 1);
    std::reverse(t + 1, t + m + 1);
    g[0] = -1;
    for (int i = 1; i <= m; ++i) {
        for (g[i] = std::min(g[i - 1] + 1, n); g[i] < n && s[g[i] + 1] != t[i]; ++g[i]) ;
    }
    //for (int i = 0; i <= m; ++i) printf("%d%c", f[i], i == m ? '\n' : ' ');
    //for (int i = 0; i <= m; ++i) printf("%d%c", g[i], i == m ? '\n' : ' ');

    int best = 0, ans_l = -1, ans_r = -1;
    for (int i = 0; i <= m; ++i) if (f[i] < n) {
        int j = std::upper_bound(g, g + m, n - f[i] - 2) - &g[0] - 1;
        j = std::min(j, m - i);
        if (best < i + j) { best = i + j; ans_l = i; ans_r = j; }
    }

    if (best == 0) puts("-");
    else {
        std::reverse(t + 1, t + m + 1);
        for (int i = 1; i <= ans_l; ++i) putchar(t[i]);
        std::reverse(t + 1, t + m + 1);
        for (int i = ans_r; i >= 1; --i) putchar(t[i]);
        putchar('\n');
    }

    return 0;
}