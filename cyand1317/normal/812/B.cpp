#include <cstdio>
#include <algorithm>
static const int MAXN = 16;
static const int MAXM = 104;
static const int INF = 0x3fffffff;

int n, m;
int f[MAXN][MAXM];
int leftmost[MAXN], rightmost[MAXN];

int main()
{
    scanf("%d%d", &n, &m); getchar();
    for (int i = n - 1; i >= 0; --i) {
        getchar();
        for (int j = 0; j < m; ++j) f[i][j] = getchar() - '0';
        getchar(); getchar();
    }

    for (int i = 0; i < n; ++i) {
        leftmost[i] = rightmost[i] = -1;
        for (int j = 0; j < m; ++j) if (f[i][j] == 1) {
            if (leftmost[i] == -1) leftmost[i] = j;
            rightmost[i] = j;
        }
    }
    for (; n > 0; --n) if (leftmost[n - 1] != -1) break;
    if (leftmost[n - 1] == -1) { puts("0"); return 0; }

    int ans_left = 0, ans_right = INF;
    int n_ans_left, n_ans_right;
    for (int i = 0; i < n - 1; ++i) if (leftmost[i] != -1) {
        n_ans_left = std::min(ans_left + (rightmost[i] + 1) * 2, ans_right + m + 1);
        n_ans_right = std::min(ans_right + (m - leftmost[i]) * 2, ans_left + m + 1);
        ans_left = n_ans_left;
        ans_right = n_ans_right;
    }

    int ans;
    if (leftmost[n - 1] != -1) {
        ans = std::min(ans_left + (rightmost[n - 1] + 1), ans_right + (m - leftmost[n - 1]));
    } else {
        ans = std::min(ans_left, ans_right);
    }

    printf("%d\n", ans + n - 1);
    return 0;
}