#include <cstdio>
#include <utility>
static const int MAXN = 321;

int n;
int f[MAXN][MAXN], frk[MAXN][MAXN];
int a[MAXN], ark[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            scanf("%d", &f[i][j]); --f[i][j];
            frk[i][f[i][j]] = j;
        }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]); --a[i];
        ark[a[i]] = i;
    }

    std::pair<int, int> f_ans[MAXN];
    for (int i = 0; i < n; ++i) f_ans[i] = std::make_pair(n + 233, -1);

    std::pair<int, int> m1, m2, t;
    m1 = m2 = std::make_pair(n + 233, -1);
    for (int i = 0; i < n; ++i) {
        t = std::make_pair(ark[i], i);
        if (t < m1) { m2 = m1; m1 = t; } else if (t < m2) { m2 = t; }
        for (int j = 0; j < n; ++j) {
            if ((m1.second == j ? m2.second : m1.second) == -1) continue;
            t = std::make_pair(frk[j][m1.second == j ? m2.second : m1.second], i);
            //printf("After card #%d sends to #%d: #%d is given out\n", i + 1, j + 1, t.first);
            if (t < f_ans[j]) f_ans[j] = t;
        }
    }

    for (int i = 0; i < n; ++i)
        printf("%d%c", f_ans[i].second + 1, i == n - 1 ? '\n' : ' ');

    return 0;
}