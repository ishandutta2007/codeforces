#include <stdio.h>
int conn[700][700];
char a[200050];
char b[200050];
int chk[700];
int CharToNum(char c) {
    return c-'a';
}
void get_conn(int x) {
    int t1 = x/26;
    int t2 = x%26;
    if(t1 == t2) return;
    conn[x][t2*26+t1] = 2;
    for(int i = 0; i < 26; i++) {
        if(i == t2) continue;
        if(i == t1) continue;
        conn[x][t2*26+i] = 1;
    }
    for(int i = 0; i < 26; i++) {
        if(i == t1 || i == t2) continue;
        conn[x][i*26+t1] = 1;
    }
    return;
}
int main() {
    int i, j, N, ans = 0;
    for(i = 0; i < 26*26; i++) get_conn(i);
    scanf("%d", &N);
    scanf("%s %s", &a[1], &b[1]);
    for(i = 1; i <= N; i++) {
        chk[CharToNum(a[i])*26+CharToNum(b[i])] = i;
        if(a[i] != b[i]) ans++;
    }
    int mx = 0, ans1 = -1, ans2 = -1;
    for(i = 0; i < 26*26; i++) {
        for(j = 0; j < 26*26; j++) {
            if(chk[i] == 0 || chk[j] == 0) continue;
            if(i == ('g'-'a')*26+('m'-'a') && j == ('m'-'a')*26+('n'-'a')) {
                i = i;
            }
            if(mx < conn[i][j]) {
                mx = conn[i][j];
                ans1 = chk[i];
                ans2 = chk[j];
            }
        }
    }
    printf("%d\n%d %d", ans-mx, ans1, ans2);
    return 0;
}