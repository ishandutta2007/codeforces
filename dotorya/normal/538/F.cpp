#include <stdio.h>
int d[200050];
int T[200050];
int sum[200050];

int main() {
    int N, i, j;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) scanf("%d", &d[i]);

    if(d[1] > d[2]) {
        T[1]++, T[N]--;
    }
    for(i = 3; i <= N; i++) {
        if(d[1] > d[i]) {
            T[i-1]++;
            T[N]--;
        }
        int c = i-2;
        for(j = 2; j*j <= i-2; j++) {
            if(d[j] > d[i]) {
                T[(i-2)/j+1]++;
                T[c+1]--;
            }
            c = (i-2)/j;
        }
        for(j = 1; j <= c; j++) {
            int v = (i-2)/j+1;
            if(d[v] > d[i]) {
                T[j]++;
                T[j+1]--;
            }
        }
    }

    for(i = 1; i < N; i++) {
        sum[i] = sum[i-1]+T[i];
        printf("%d ", sum[i]);
    }
    return 0;
}