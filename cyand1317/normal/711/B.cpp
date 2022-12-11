#include <cstdio>
typedef long long int64;
static const int MAXN = 512;

int n;
int64 a[MAXN][MAXN];
int row = -1, col = -1;
int64 rsum[MAXN] = { 0 }, csum[MAXN] = { 0 }, dsum[2] = { 0 };

int main()
{
    scanf("%d", &n);
    if (n == 1) { puts("15532"); return 0; }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            scanf("%I64d", &a[i][j]);
            if (a[i][j] == 0) { row = i; col = j; }
            rsum[i] += a[i][j];
            csum[j] += a[i][j];
            if (i == j) dsum[0] += a[i][j];
            if (i + j == n - 1) dsum[1] += a[i][j];
        }

    a[row][col] = (row == 0 ? rsum[1] : rsum[0]) - rsum[row];
    rsum[row] += a[row][col];
    csum[col] += a[row][col];
    if (row == col) dsum[0] += a[row][col];
    if (row + col == n - 1) dsum[1] += a[row][col];

    bool valid = true;
    if (a[row][col] <= 0) valid = false;
    for (int i = 1; i < n; ++i) if (rsum[i] != rsum[0]) { valid = false; break; }
    for (int i = 0; i < n; ++i) if (csum[i] != rsum[0]) { valid = false; break; }
    for (int i = 0; i < 2; ++i) if (dsum[i] != rsum[0]) { valid = false; break; }
    printf("%I64d\n", valid ? a[row][col] : -1);

    return 0;
}