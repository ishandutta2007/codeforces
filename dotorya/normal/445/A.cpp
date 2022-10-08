#include <stdio.h>
char d[105][105];
int main() {
    int i, j, N, M;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; i++) {
        scanf("%s", &d[i][1]);
        for(j = 1; j <= M; j++) {
            if(d[i][j] == '-') continue;
            if((i+j)&1) d[i][j] = 'B';
            else d[i][j] = 'W';
        }
    }
    for(i = 1; i <= N; i++) printf("%s\n", &d[i][1]);
    return 0;
}