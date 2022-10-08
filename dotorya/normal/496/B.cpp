#include <stdio.h>
char d[1050];
char min[1050];
int main() {
    int N, i, j, k, chk;
    scanf("%d %s", &N, d);
    for(i = 0; i < N; i++) min[i] = d[i];
    for(i = 0; i <= 9; i++) {
        for(j = 0; j < N; j++) {
            chk = 0;
            for(k = 0; k < N; k++) {
                if(d[(j+k)%N] < min[k]) {
                    chk = 1;
                    break;
                }
                if(d[(j+k)%N] > min[k]) break;
            }
            if(chk == 1) {
                for(; k < N; k++) min[k] = d[(j+k)%N];
            }
        }
        for(k = 0; k < N; k++) {
            if(d[k] == '9') d[k] = '0';
            else d[k] = d[k]+1;
        }
    }
    printf("%s", min);
    return 0;
}