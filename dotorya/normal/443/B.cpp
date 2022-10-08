#include <stdio.h>
char d[205];
int main() {
    int L, K;
    scanf("%s", d);
    for(L = 0; d[L] != 0; L++);
    scanf("%d", &K);

    // Brute Force
    if(K >= L) {
        printf("%d", 2*((K+L)/2));
        return 0;
    }

    int MAX = K, i, j, k;
    for(i = K+1; 2*i <= K+L; i++) {
        for(j = L+K-2*i; j >= 0; j--) {
            for(k = 0; k < i; k++) {
                if(j+k+i >= L) continue;
                if(d[j+k] != d[j+k+i]) break;
            }
            if(k == i) break;
        }
        if(j >= 0) MAX = i;
    }

    printf("%d", MAX*2);
    return 0;
}