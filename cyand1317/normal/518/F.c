#include <stdio.h>
#include <string.h>
#define MAXN 2002

int n, m;
long long ans0 = 0, ans1 = 0, ans2 = 0;
unsigned short map[MAXN][MAXN];

int rowcnt[MAXN][MAXN], colcnt[MAXN][MAXN];
int left[MAXN][MAXN], right[MAXN][MAXN], sumup[MAXN][MAXN], sumdown[MAXN][MAXN];
void calc()
{
    int i, j;

    // Calculate the arrays rowcnt and colcnt.
    for (i = 0; i < n; i++) {
        rowcnt[i][0] = map[i][0];
        for (j = 0; j < m; j++) rowcnt[i][j] = rowcnt[i][j - 1] + map[i][j];
    }
    for (j = 0; j < m; j++) {
        colcnt[0][j] = map[0][j];
        for (i = 1; i < n; i++) colcnt[i][j] = colcnt[i - 1][j] + map[i][j];
    }
    // Calculate ans0.
    for (i = 1; i < n - 1; i++) if (rowcnt[i][m - 1] == 0) ++ans0;
    // Calculate ans1.
    for (i = 1; i < n - 1; i++)
        for (j = 1; j < m - 1; j++)
            if (rowcnt[i][j] == 0 && colcnt[i][j] == 0) ++ans1;

    // Calculate the arrays left, right, sumup and sumdown.
    for (i = 0; i < n; i++) {
        int last = -1; j = 0;
        do {
            while (j < m && !map[i][j]) left[i][j++] = last;
            last = j++;
        } while (j < m);
        last = m; j = m - 1;
        do {
            while (j >= 0 && !map[i][j]) right[i][j--] = last;
            last = j--;
        } while (j >= 0);
    }
    sumup[0][0] = !map[0][0];
    for (j = 1; j < m; j++) sumup[0][j] = sumup[0][j - 1] + !map[0][j];
    for (i = 1; i < n; i++) {
        sumup[i][0] = colcnt[i][0] == 0;
        sumdown[i][0] = colcnt[i - 1][0] == colcnt[n - 1][0];
        for (j = 1; j < m; j++) {
            sumup[i][j] = sumup[i][j - 1] + (colcnt[i][j] == 0);
            sumdown[i][j] = sumdown[i][j - 1] + (colcnt[i - 1][j] == colcnt[n - 1][j]);
        }
    }
    // Calculate ans2.
    // Brute the cell to be the first bending.
    for (i = 1; i < n - 1; i++)
        for (j = 1; j < m - 1; j++) if (colcnt[i][j] == 0) {
            int lopen = left[i][j] + 1, ropen = right[i][j] - 1;
            if (lopen == 0) lopen++;
            if (ropen == m - 1) ropen--;
            ans2 += sumup[i][ropen] - sumup[i][lopen - 1] - 1;
            ans2 += sumdown[i][ropen] - sumdown[i][lopen - 1]
                - (colcnt[i - 1][j] == colcnt[n - 1][j]);
        }
    // Remove things like (0, j) -> (i, j) -> (i, j + 1) -> (0, j + 1)
    // where 1 <= j <= m - 3
    for (i = 1; i < n - 1; i++)
        for (j = 1; j < m - 2; j++)
            if (colcnt[i][j] == 0 && colcnt[i][j + 1] == 0) ans2 -= 2;
}

// Rotates the whole map by 90 degree.
unsigned short newmap[MAXN][MAXN];
void rotate()
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) newmap[m - j - 1][i] = map[i][j];
    int t = m; m = n; n = t;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) map[i][j] = newmap[i][j];
}

int main()
{
    scanf("%d%d", &n, &m);
    int i, j;
    for (i = 0; i < n; i++) {
        getchar();
        for (j = 0; j < m; j++) map[i][j] = getchar() == '#';
    }

    calc(); rotate(); calc(); rotate(); calc(); rotate(); calc();
    printf("%I64d\n", ans0 / 2 + ans1 + ans2 / 2);

    return 0;
}