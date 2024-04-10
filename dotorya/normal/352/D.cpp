#include <stdio.h>
int d[3050];
int main() {
    int N, i, j, cnt = 0;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) scanf("%d", &d[i]);

    for(i = 1; i <= N; i++) {
        for(j = i+1; j <= N; j++) {
            if(d[i] > d[j]) cnt++;
        }
    }
    if(cnt % 2 == 1) printf("%d", cnt*2-1);
    else printf("%d", cnt*2);
    return 0;
}