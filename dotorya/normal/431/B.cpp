#include <stdio.h>
int g[6][6];
int c[6];
int chk[6];
int mx = -1;
void aa(int lvl) {
    if (lvl == 6) {
        int t = g[c[1]][c[2]] + g[c[2]][c[1]] + g[c[2]][c[3]] + g[c[3]][c[2]] + 2 * g[c[3]][c[4]] + 2 * g[c[4]][c[3]] + 2 * g[c[4]][c[5]] + 2 * g[c[5]][c[4]];
        if (mx < t) mx = t;
        return;
    }
    int i;
    for (i = 1; i <= 5; i++) {
        if (chk[i] == 1) continue;
        chk[i] = 1;
        c[lvl] = i;
        aa(lvl + 1);
        chk[i] = 0;
    }
    return;
}
int main() {
    int i, j;
    for (i = 1; i <= 5; i++) for (j = 1; j <= 5; j++) scanf("%d", &g[i][j]);
    aa(1);
    printf("%d", mx);
    return 0;
}