#include <stdio.h>
long long ans[200050];
int main() {
    int T, K, i, a, b;
    long long ANS;
    scanf("%d %d", &T, &K);
    for(i = 0; i < K; i++) ans[i] = 1;
    for(i = K; i <= 200000; i++) ans[i] = (ans[i-1]+ans[i-K])%1000000007;
    for(int t = 1; t <= T; t++) {
        scanf("%d %d", &a, &b);
        ANS = ans[b+K] - ans[a+K-1];
        if(ANS < 0) ANS += 1000000007;
        printf("%lld\n", ANS);
    }
    return 0;
}