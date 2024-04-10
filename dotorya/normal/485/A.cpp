#include <stdio.h>
int main() {
    int A, M;
    scanf("%d %d", &A, &M);
    for(int i = 1; i <= 100050; i++) {
        A = (2*A)%M;
    }
    if(A == 0) printf("Yes");
    else printf("No");
    return 0;
}