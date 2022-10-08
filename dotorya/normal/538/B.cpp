#include <stdio.h>
char s[10];
char ans[10][10];
int main() {
    scanf("%s", s);
    int L, i, j, max = 0;
    for(L = 0; s[L] != 0; L++){
        if(max < s[L]-'0') max = s[L]-'0';
    }
    printf("%d\n", max);

    for(i = 1; i <= max; i++) {
        for(j = 0; j < L; j++) {
            if(s[j] != '0') {
                ans[i][j] = '1';
                s[j]--;
            }
            else ans[i][j] = '0';
        }
    }
    for(i = 1; i <= max; i++) {
        for(j = 0; ans[i][j] == '0'; j++);
        for(;j < L; j++) printf("%c", ans[i][j]);
        printf(" ");
    }
    return 0;
}