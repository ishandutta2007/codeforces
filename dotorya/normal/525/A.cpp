#include <stdio.h>
char d[300050];
int chk[26];
int main() {
    int ANS = 0, i, N;
    scanf("%d", &N);
    scanf("%s", d);
    for(i = 0; i < 2*N-2; i++) {
        if(i%2 == 0) chk[d[i]-'a']++;
        else {
            if(chk[d[i]-'A'] >= 1) {
                chk[d[i]-'A']--;
                continue;
            }
            ANS++;
        }
    }
    printf("%d", ANS);
    return 0;
}