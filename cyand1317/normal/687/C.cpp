#include <cstdio>
static const int MAXN = 512;
static const int MAXK = 512;

int n, k;
int c[MAXN];
int _f_cur = 0;
#define f_cur  f[_f_cur]
#define f_last f[_f_cur ^ 1]
bool f[2][MAXK][MAXK] = {{{ false }}};
// f[*][i][j] = whether a subset of sum i can form a sum of j... Uh - -||

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);

    f_cur[0][0] = true;
    for (int p = 0; p < n; ++p) {
        _f_cur ^= 1;
        for (int i = 0; i <= k; ++i)
            for (int j = 0; j <= k; ++j) {
                f_cur[i][j] = f_last[i][j];
                if (i - c[p] >= 0) {
                    f_cur[i][j] |= f_last[i - c[p]][j];
                    if (j - c[p] >= 0)
                        f_cur[i][j] |= f_last[i - c[p]][j - c[p]];
                }
            }
    }

    int ct = 0;
    for (int i = 0; i <= k; ++i) if (f_cur[k][i]) ++ct;
    printf("%d\n", ct);
    for (int i = 0; i <= k; ++i) if (f_cur[k][i]) printf("%d ", i);
    putchar('\n');
    return 0;
}