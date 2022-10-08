#include <stdio.h>
char d[1050];
int chk[26];
int main() {
    int N, i;
    scanf("%d", &N);
    scanf("%s", d);
    for(i = 0; i < N; i++) {
        if(d[i] >= 'a' && d[i] <= 'z') chk[d[i]-'a']++;
        else chk[d[i]-'A']++;
    }
    for(i = 0; i < 26; i++) if(chk[i] == 0) break;
    if(i == 26) printf("YES");
    else printf("NO");
    return 0;
}