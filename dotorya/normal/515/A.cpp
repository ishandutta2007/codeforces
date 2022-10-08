#include <stdio.h>
int main() {
    long long A, B, S;
    scanf("%lld %lld %lld", &A, &B, &S);
    if(A+B > S || A+B < -S || A-B > S || A-B < -S) printf("No");
    else if((A+B-S)%2 != 0) printf("No");
    else printf("Yes");
    return 0;
}