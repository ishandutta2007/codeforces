#include <stdio.h>
int conn[105][105][105];
int chk[105][105];
int queue[105];
int main() {
    int N, M, Q, i, j, k, t1, t2, t3, st, en;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= M; i++) {
        scanf("%d %d %d", &t1, &t2, &t3);
        conn[t3][t1][t2] = 1;
        conn[t3][t2][t1] = 1;
    }
    for(i = 1; i <= M; i++) {
        t3 = 1;
        for(j = 1; j <= N; j++) {
            if(chk[i][j] != 0) continue;
            st = 1, en = 2;
            queue[1] = j;
            chk[i][j] = t3;
            while(st < en) {
                t1 = queue[st];
                for(k = 1; k <= N; k++) {
                    if(conn[i][t1][k] == 0) continue;
                    if(chk[i][k] != 0) continue;
                    chk[i][k] = t3;
                    queue[en++] = k;
                }
                st++;
            }
            t3++;
        }
    }
    scanf("%d", &Q);
    for(i = 1; i <= Q; i++) {
        scanf("%d %d", &t1, &t2);
        t3 = 0;
        for(j = 1; j <= M; j++) {
            if(chk[j][t1] == chk[j][t2]) t3++;
        }
        printf("%d\n", t3);
    }
    return 0;
}