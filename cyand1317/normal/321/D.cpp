#include <cstdio>
static const int INF = 0x7fffffff;
static const int MAXN = 33;
static const int MAXX = 17;
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }
template <typename T> inline T abs(const T x) { return x > 0 ? x : -x; }

int n, x;
int a[MAXN][MAXN];
short centre_row[MAXN], centre_col;
static const int mul[2] = { 1, -1 };

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) scanf("%d", &a[i][j]);

    x = (n + 1) / 2;
    int ans = -INF, sum;
    for (int mask = 0; mask < (1 << x); ++mask) {
        sum = 0;
        for (int i = 0; i < x; ++i) centre_row[i] = (mask >> i) & 1;
        for (int i = x; i < n; ++i) centre_row[i] = ((mask >> (x - 1)) & 1) ^ centre_row[i - x];
        for (int i = 0; i < n; ++i) sum += a[x - 1][i] * mul[centre_row[i]];

        //printf("%d: CRow = %d\n", mask, sum);
        for (int i = 0; i < x - 1; ++i) {
            int cur = -INF;
            for (centre_col = 0; centre_col <= 1; ++centre_col) {
                int sol = a[i][x - 1] * mul[centre_col] + a[i + x][x - 1] * mul[centre_col ^ centre_row[x - 1]];
                for (int j = 0; j < x - 1; ++j)
                    sol += abs(a[i][j] + a[i][j + x] * mul[centre_col] + a[i + x][j] * mul[centre_row[j]] + a[i + x][j + x] * mul[centre_col ^ centre_row[j] ^ centre_row[x - 1]]);
                cur = max(cur, sol);
            }
            sum += cur;
            //printf("%d: Row %d,%d sum = %d\n", mask, i, i + x, cur);
        }
        //printf("%d: Sum = %d\n", mask, sum);
        ans = max(ans, sum);
    }

    printf("%d\n", ans);
    return 0;
}