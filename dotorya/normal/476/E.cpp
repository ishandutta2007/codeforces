#include <stdio.h>
char S[2050];
char P[550];
int L_S, L_P;
int d[2050];
int ans[2050][2050];
int ANS[2050];
int min(int a, int b) {
    if(a<b) return a;
    else return b;
}
void input() {
    int i, j, t;
    scanf("%s %s", S, P);
    for(L_S = 0; S[L_S] != 0; L_S++);
    for(L_P = 0; P[L_P] != 0; L_P++);
    for(i = 0; i < L_S; i++) {
        if(i < L_P-1) d[i] = -1;
        else if(S[i] != P[L_P-1]) d[i] = -1;
        else if(L_P == 1) d[i] = i;
        else {
            t = L_P-2;
            for(j = i-1; j >= 0; j--) {
                if(S[j] == P[t]) t--;
                if(t == -1) break;
            }
            d[i] = j;
        }
    }
    return;
}
void get_ans() {
    int i, j, mx_ans, t;
    for(i = 0; i < L_S; i++) for(j = 0; j <= L_S+5; j++) ans[i][j] = -1;
    ans[0][0] = 0;
    for(i = 1; i <= L_S; i++) {
        for(j = 0; j <= L_S+5; j++) {
            ans[i][j] = ans[i-1][j];
            if(j == 0) continue;
            if(d[i-1] != -1 && ans[d[i-1]][j-1] != -1) {
                if(ans[i][j] == -1) ans[i][j] = ans[d[i-1]][j-1]+i-d[i-1]-L_P;
                else ans[i][j] = min(ans[d[i-1]][j-1]+i-d[i-1]-L_P, ans[i][j]);
            }
        }
    }
    for(mx_ans = 0; ans[L_S][mx_ans] != -1; mx_ans++);
    mx_ans--;
    for(i = 0; i <= mx_ans*L_P; i++) ANS[i] = i/L_P;
    t = mx_ans;
    for(i = mx_ans*L_P+1; i <= L_S; i++) {
        while(L_S-i < ans[L_S][t] && t >= 1) t--;
        ANS[i] = t;
    }
    for(i = L_S; i >= 0; i--) printf("%d ", ANS[i]);
    return;
}
int main() {
    input();
    get_ans();
    return 0;
}