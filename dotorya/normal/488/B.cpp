#include <stdio.h>
#include <algorithm>
int d[5];
int main() {
    int N, i;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) scanf("%d", &d[i]);
    if(N == 0) {
        printf("YES\n1\n1\n3\n3");
        return 0;
    }
    if(N == 1) {
        printf("YES\n%d\n%d\n%d", d[1], 3*d[1], 3*d[1]);
        return 0;
    }
    if(N == 4) {
        std::sort(d+1, d+5);
        if(d[4] != 3*d[1] || d[2]+d[3] != 4*d[1]) printf("NO");
        else printf("YES");
        return 0;
    }
    if(N == 2) {
        std::sort(d+1, d+3);
        if(d[2] > 3*d[1]) printf("NO");
        else if(d[2] == 3*d[1]) printf("YES\n%d\n%d", d[1], 3*d[1]);
        else printf("YES\n%d\n%d", 4*d[1]-d[2], 3*d[1]);
        return 0;
    }
    std::sort(d+1, d+4);
    if(d[3] == 3*d[1]) printf("YES\n%d", 4*d[1]-d[2]);
    else if(d[2]+d[3] == 4*d[1]) printf("YES\n%d", 3*d[1]);
    else if(d[3] % 3 == 0 && (d[3]*4)/3 == d[1]+d[2]) printf("YES\n%d", d[3]/3);
    else printf("NO");
    return 0;
}