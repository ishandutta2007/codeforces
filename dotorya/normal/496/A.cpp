#include <stdio.h>
int d[105];
int main() {
    int max = 0, N, i, min = 2;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) scanf("%d", &d[i]);
    for(i = 2; i <= N; i++) {
        if(d[i]-d[i-1] > max) max = d[i]-d[i-1];
    }
    for(i = 2; i <= N-1; i++) {
        if(d[i+1]-d[i-1] <= max) break;
        if(d[min+1]-d[min-1] > d[i+1]-d[i-1]) min = i;
    }
    if(i != N) printf("%d", max);
    else printf("%d", d[min+1]-d[min-1]);
    return 0;
}