#include <stdio.h>
long long divide[100050];
int chk[100];
int main() {
    int N, i, t, j;
    long long t2, t3;
    scanf("%d", &N);
    if(N == 1) {
        printf("YES\n1");
        return 0;
    }
    if(N == 4) {
        printf("YES\n1\n3\n2\n4");
        return 0;
    }
    for(i = 2; i*i <= N; i++) {
        if(N%i == 0) break;
    }
    if(i*i <= N) {
        printf("NO");
        return 0;
    }
    t = N-2, i = 0;
    while(t > 0) {
        chk[i] = t%2;
        i++;
        t /= 2;
    }
    for(i = 1; i <= N-1; i++) {
        t2 = 1, t3 = i;
        for(j = 0; j <= 40; j++) {
            if(chk[j] == 1) t2 = (t2*t3)%N;
            t3 = (t3*t3)%N;
        }
        divide[i] = t2;
    }
    printf("YES\n1\n");
    for(i = 1; i <= N-1; i++) printf("%lld\n", ((i+1)*divide[i]-1)%N+1);
    return 0;
}