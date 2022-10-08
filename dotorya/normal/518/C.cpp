#include <stdio.h>
int d[100050];
int rev_d[100050];

int main() {
    int N, M, K, i, x;
    scanf("%d %d %d", &N, &M, &K);
    for(i = 1; i <= N; i++) {
        scanf("%d", &d[i]);
        rev_d[d[i]] = i;
    }

    long long ANS = 0;
    for(i = 1; i <= M; i++) {
        scanf("%d", &x);
        int t = rev_d[x];
        ANS += (t-1)/K+1;
        if(t == 1) continue;
        int x2 = d[t-1];
        d[t] = x2;
        d[t-1] = x;
        rev_d[x2] = t;
        rev_d[x] = t-1;
    }

    printf("%lld", ANS);
    return 0;
}