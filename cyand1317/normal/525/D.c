// Long time no C (  )
// Fixed from submission #10650044
#include <stdio.h>
#include <stdlib.h>
#define MAXM 2003

const int direction[8][2] = {
    {-1, -1}, {-1, 0}, {-1, +1},
    { 0, -1},          { 0, +1},
    {+1, -1}, {+1, 0}, {+1, +1}
};

int main()
{
    int n, m, i, j, k, z[8];
    unsigned short g[MAXM][MAXM];
    scanf("%d%d", &n, &m);
    for (j = 0; j <= m + 1; j++) g[0][j] = g[n + 1][j] = 1;
    for (i = 1; i <= n; i++) {
        getchar();
        g[i][0] = g[i][m + 1] = 1;
        for (j = 1; j <= m; j++) g[i][j] = getchar() == '*';
    }
    n += 2; m += 2;

    // Standard BFS.
    int *q, qfront = 0, qtail = 0;
    q = (int *)malloc(MAXM * MAXM * sizeof(int));
    // Initialization
    // Skip outer borders since they don't need to be changed
    for (i = 1; i < n - 1; i++)
        for (j = 1; j < m - 1; j++) if (g[i][j]) {
            for (k = 0; k < 8; k++) z[k] = !g[i + direction[k][0]][j + direction[k][1]];
            if ((z[1] && z[0] && z[3]) || (z[1] && z[2] && z[4]) ||
                    (z[6] && z[5] && z[3]) || (z[6] && z[7] && z[4])) {
                q[qfront++] = i * m + j;
                g[i][j] = 0;
            }
        }
    int ii, jj, kk;
    while (qtail < qfront) {
        int out = q[qtail++];
        i = out / m; j = out % m;
        for (k = 0; k < 8; k++) {
            // Check every 1x1 square that might come out after removing (i, j)
            ii = i + direction[k][0]; jj = j + direction[k][1];
            if (ii == 0 || ii == n - 1 || jj == 0 || jj == m - 1 || !g[ii][jj]) continue;
            for (kk = 0; kk < 8; kk++) z[kk] = !g[ii + direction[kk][0]][jj + direction[kk][1]];
            if ((z[1] && z[0] && z[3]) || (z[1] && z[2] && z[4]) ||
                    (z[6] && z[5] && z[3]) || (z[6] && z[7] && z[4])) {
                q[qfront++] = ii * m + jj;
                g[ii][jj] = 0;
            }
        }
    }

    for (i = 1; i < n - 1; i++) {
        for (j = 1; j < m - 1; j++) putchar(g[i][j] ? '*' : '.');
        putchar('\n');
    }
    return 0;
}