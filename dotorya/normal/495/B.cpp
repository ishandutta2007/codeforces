#include <stdio.h>
int main() {
    int A, B;
    scanf("%d %d", &A, &B);
    if(A == B) {
        printf("infinity");
        return 0;
    }
    if(A < B) {
        printf("0");
        return 0;
    }

    int C = A-B, cnt = 0;
    for(int i = 1; i*i <= C; i++) {
        if(C%i != 0) continue;
        if(B<i) cnt++;
        if(i*i == C) continue;
        if(B<C/i) cnt++;
    }
    printf("%d", cnt);
    return 0;
}