#include <stdio.h>
#include <algorithm>
using namespace std;
int plus[5050];
int d[5050];
int tmp[5050];
int d2[5050][4];
int main() {
    int N, M, i, j, t, l, r, x;
    scanf("%d %d", &N, &M);
    for(i = 1; i <= N; i++) d[i] = 100000000;
    for(i = 1; i <= M; i++) {
        scanf("%d %d %d %d", &t, &l, &r, &x);
        d2[i][0] = t, d2[i][1] = l, d2[i][2] = r, d2[i][3] = x;
        if(t == 1) {
            for(j = l; j <= r; j++) plus[j] += x;
            continue;
        }
        for(j = l; j <= r; j++) d[j] = min(d[j], x-plus[j]);
    }

    for(i = 1; i <= N; i++) tmp[i] = d[i];
    for(i = 1; i <= M; i++) {
        t = d2[i][0], l = d2[i][1], r = d2[i][2], x = d2[i][3];
        if(t == 1) {
            for(j = l; j <= r; j++) tmp[j] += x;
            continue;
        }
        for(j = l; j <= r; j++) if(tmp[j] == x) break;
        if(j == r+1) break;
    }
    if(i != M+1) {
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for(i = 1; i <= N; i++) printf("%d ", d[i]);
    return 0;
}