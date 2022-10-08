#include <stdio.h>
long long t[100050];
long long t_sum[100050];
int t2[100050];
int t2_sum[100050];
long long d[100050];
long long op[100050][3];
int main() {
    int N, M, K, i, x, y;
    scanf("%d %d %d", &N, &M, &K);
    for(i = 1; i <= N; i++) scanf("%d", &d[i]);
    for(i = 1; i <= M; i++) scanf("%I64d %I64d %I64d", &op[i][0], &op[i][1], &op[i][2]);
    for(i = 1; i <= K; i++) {
        scanf("%d %d", &x, &y);
        t2[x]++;
        if(y != M) t2[y+1]--;
    }
    for(i = 1; i <= M; i++) {
        t2_sum[i] = t2_sum[i-1]+t2[i];
        t[op[i][0]] += op[i][2]*t2_sum[i];
        if(op[i][1] != N) t[op[i][1]+1] -= op[i][2]*t2_sum[i];
    }
    for(i = 1; i <= N; i++) {
        t_sum[i] = t_sum[i-1]+t[i];
        d[i] += t_sum[i];
        printf("%I64d ", d[i]);
    }
    return 0;
}