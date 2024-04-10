#include <stdio.h>
#define MAXN    103

int n, m, k;
int a[MAXN][MAXN];

int main()
{
    int i, j, p;

    scanf("%d%d%d", &n, &m, &k);
    for (i = 0; i < n; ++i)
        for (j = 0; j < m; ++j) scanf("%d", &a[i][j]);

    int ans = 0, ans_rep = 0;
    int best, best_rep, cur, cur_rep;

    for (j = 0; j < m; ++j) {
        best = best_rep = -1;
        cur_rep = 0;
        for (i = 0; i < n; ++i) if (a[i][j] == 1) {
            cur = 0;
            for (p = i; p < i + k && p < n; ++p)
                cur += a[p][j];
            if (best < cur) {
                best = cur;
                best_rep = cur_rep;
            }
            ++cur_rep;
        }
        if (best != -1) {
            ans += best;
            ans_rep += best_rep;
        }
    }
    printf("%d %d\n", ans, ans_rep);

    return 0;
}