#include <stdio.h>
int b[105];
int g[105];
int conn[205][205];
int queue[205];
int chk[205];
int main() {
    int N, M, i, B, G, t; 
    scanf("%d %d %d", &N, &M, &B);
    for(i = 1; i <= B; i++) {
        scanf("%d", &t);
        b[t] = 1;
    }
    scanf("%d", &G);
    for(i = 1; i <= G; i++) {
        scanf("%d", &t);
        g[t] = 1;
    }
    for(i = 1; i <= N*M; i++) conn[i%N][i%M+N] = conn[i%M+N][i%N] = 1;
    int st = 1, en = 1;
    for(i = 0; i < N; i++) {
        if(b[i] == 1) {
            queue[en] = i;
            en++;
            chk[i] = 1;
        }
    }
    for(i = N; i < N+M; i++) {
        if(g[i-N] == 1) {
            queue[en] = i;
            en++;
            chk[i] = 1;
        }
    }
    while(st < en) {
        t = queue[st];
        for(i = 0; i < N+M; i++) {
            if(chk[i] == 1) continue;
            if(conn[t][i] == 0) continue;
            queue[en] = i;
            chk[i] = 1;
            en++;
        }
        st++;
    }
    if(st == N+M+1) printf("Yes");
    else printf("No");
    return 0;
}