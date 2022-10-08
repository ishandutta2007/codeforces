#include <stdio.h>
char d[3050][2][15];
int len[3050][2];
char t[3050];
int main() {
    int N, M, i, j, k;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= M; i++) {
        scanf("%s %s", d[i][0], d[i][1]);
        for(len[i][0] = 0; d[i][0][len[i][0]] != 0; len[i][0]++);
        for(len[i][1] = 0; d[i][1][len[i][1]] != 0; len[i][1]++);
    }
    for(i = 1; i <= N; i++) {
        scanf("%s", t);
        for(j = 1; j <= M; j++) {
            for(k = 0; k < len[j][0]; k++) if(d[j][0][k] != t[k]) break;
            if(k == len[j][0] && t[k] == 0) {
                if(len[j][0] <= len[j][1]) printf("%s ", d[j][0]);
                else printf("%s ", d[j][1]);
                break;
            }
        }
        for(j = 0; t[j] != 0; j++) t[j] = 0;
    }
    return 0;
}