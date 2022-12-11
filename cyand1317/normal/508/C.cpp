#include <cstdio>
static const int MAXN = 305;

int m, t, r;
int w[MAXN];
bool put[MAXN * 2] = { false };

int main()
{
    scanf("%d%d%d", &m, &t, &r);
    for (int i = 0; i < m; ++i) { scanf("%d", &w[i]); w[i] += MAXN; }

    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int sum = 0;
        for (int j = w[i] - 1; j >= w[i] - t; --j) sum += put[j];
        for (int j = w[i] - 1; j >= w[i] - (r - sum); --j)
            if (j < w[i] - t || put[j]) { puts("-1"); return 0; }
            else { put[j] = true; ++ans; }
    }

    printf("%d\n", ans);
    return 0;
}