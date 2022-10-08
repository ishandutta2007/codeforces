#include <stdio.h>
int main() {
    long long N, M;
    scanf("%lld %lld", &N, &M);
    long long ans = 0;
    ans += ((N/M+1) * (N/M) / 2)*(N%M);
    ans += ((N/M-1) * (N/M) / 2)*(M-N%M);
    printf("%lld %lld", ans, (N-M+1)*(N-M)/2);
    return 0;
}