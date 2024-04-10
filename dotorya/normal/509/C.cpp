#include <stdio.h>
struct BigInt {
    int d[350], L, sum;
} ans[350];
int d[350];
int main() {
    int i, j, N, t, k, t2;
    scanf("%d", &N);
    ans[0].d[0] = 0;
    ans[0].L = 1;
    ans[0].sum = 0;
    for(i = 1; i <= N; i++) {
        scanf("%d", &t);
        ans[i].L = ans[i-1].L;
        if(t > ans[i-1].sum) {
            for(j = 0; j < ans[i].L; j++) ans[i].d[j] = ans[i-1].d[j];
            ans[i].sum = ans[i-1].sum;
            for(j = 0; j < ans[i].L; j++) {
                if(ans[i].sum+9-ans[i].d[j] >= t) {
                    ans[i].d[j] = t-ans[i].sum+ans[i].d[j];
                    break;
                }
                else {
                    ans[i].sum += 9-ans[i].d[j];
                    ans[i].d[j] = 9;
                }
            }
            if(j != ans[i].L) {
                ans[i].sum = t;
                continue;
            }
            ans[i].L = (t+8)/9;
            for(j = 0; j < ans[i].L-1; j++) ans[i].d[j] = 9;
            ans[i].d[ans[i].L-1] = (t+8)%9+1;
        }
        else {
            for(j = 0; j < ans[i].L; j++) ans[i].d[j] = ans[i-1].d[j];
            ans[i].sum = ans[i-1].sum;
            for(j = 1; j < ans[i].L; j++) {
                if(ans[i].d[j] == 9) continue;
                ans[i].d[j]++;
                ans[i].sum++;
                for(k = 0; k < j; k++) {
                    ans[i].sum -= ans[i].d[k];
                    ans[i].d[k] = 0;
                }
                if(ans[i].sum <= t) {
                    t2 = t-ans[i].sum;
                    for(k = 0;;k++) {
                        if(t2 <= 9) {
                            ans[i].d[k] = t2;
                            break;
                        }
                        ans[i].d[k] = 9;
                        t2-=9;
                    }
                    break;
                }
            }
            if(j == ans[i].L) {
                ans[i].L = ans[i-1].L+1;
                ans[i].d[ans[i].L-1] = 1;
                t2 = t-1;
                for(k = 0;;k++) {
                    if(t2 <= 9) {
                        ans[i].d[k] = t2;
                        break;
                    }
                    ans[i].d[k] = 9;
                    t2-=9;
                }
                for(k = k+1;k<ans[i].L-1;k++) ans[i].d[k] = 0;
            }
        }
        ans[i].sum = t;
    }
    for(i = 1; i <= N; i++) {
        for(j = ans[i].L-1; j >= 0; j--) printf("%d", ans[i].d[j]);
        printf("\n");
    }
    return 0;
}