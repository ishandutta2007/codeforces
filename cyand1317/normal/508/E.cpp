#include <cstdio>
static const int MAXN = 603;
static const int MAXD = 1203;

int n, l[MAXN], r[MAXN];
// f[left index][right index]
// whether it's possible to fill a contiguous segment with bracket pairs numbered [left, right]
bool f[MAXN][MAXN] = {{ false }};
int decision[MAXN][MAXN];

void print_answer(int left, int right)
{
    if (left > right) return;
    if (decision[left][right] == -1) {
        putchar('('); print_answer(left + 1, right); putchar(')');
    } else {
        print_answer(left, left + decision[left][right]);
        print_answer(left + decision[left][right] + 1, right);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &l[i], &r[i]);

    for (int i = 0; i < n; ++i) { f[i][i] = (l[i] == 1); decision[i][i] = -1; }
    for (int d = 1; d < n; ++d) {
        for (int i = 0; i < n - d; ++i) {
            // (1) #i encloses around segment #(i+1) ~ #(i+d)
            if (f[i + 1][i + d] && l[i] <= d * 2 + 1 && d * 2 + 1 <= r[i]) {
                f[i][i + d] = true; decision[i][i + d] = -1; continue;
            }
            // (2) Segment is split into #i ~ #(i+j) and #(i+j+1) ~ #d
            for (int j = 0; j < d; ++j)
                if (f[i][i + j] && f[i + j + 1][i + d]) {
                    f[i][i + d] = true; decision[i][i + d] = j; break;
                }
        }
    }
    /*for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j) printf("[%d][%d]%d%c", i, j, f[i][j], j == n - 1 ? '\n' : ' ');*/

    if (!f[0][n - 1]) puts("IMPOSSIBLE");
    else { print_answer(0, n - 1); putchar('\n'); }

    return 0;
}