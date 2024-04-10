#include <stdio.h>
int abs(int x) {
    return (x>0)?x:-x;
}
int MAX(int a, int b) {
    return (a>b)?a:b;
}
int MIN(int a, int b) {
    return (a>b)?b:a;
}
int time(int a, int b, int c) {
    int t = abs(a-b);
    return (t+c-1)/c;
}
int ANS[105];
int main() {
    int V1, V2, T, D, st, en, mi, MX = 0, i, j, k1, k2, tmp;
    scanf("%d %d %d %d", &V1, &V2, &T, &D);
    if(D == 0) {
        printf("%d", V1*T);
        return 0;
    }
    for(st = 1; st <= 2000; st++) {
        if(time(V1, st, D)+time(V2, st, D) >= T) continue;
        for(i = 1; i <= T; i++) ANS[i] = 0;
        ANS[1] = V1, ANS[T] = V2;
        if(V1 != st) {
            for(i = 2;;i++) {
                if(st > V1) {
                    ANS[i] = MIN(ANS[i-1]+D, st);
                    if(ANS[i] == st) break;
                }
                else {
                    ANS[i] = MAX(ANS[i-1]-D, st);
                    if(ANS[i] == st) break;
                }
            }
        }
        if(V2 != st) {
            for(i = T-1;;i--) {
                if(st > V2) {
                    ANS[i] = MIN(ANS[i+1]+D, st);
                    if(ANS[i] == st) break;
                }
                else {
                    ANS[i] = MAX(ANS[i+1]-D, st);
                    if(ANS[i] == st) break;
                }
            }
        }
        tmp = 0;
        for(i = 1; i <= T; i++) {
            if(ANS[i] != 0) tmp += ANS[i];
            else tmp += st;
        }
        if(tmp > MX) MX = tmp;
    }
    printf("%d", MX);
    return 0;
}