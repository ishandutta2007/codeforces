#include <stdio.h>
int isBowel(char x) {
    if(x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' || x == 'Y') return 1;
    else return 0;
}
char t[500050];
long long d[500050];
long long sum[500050];
int main() {
    int i, N, L;
    scanf("%s", &t[1]);
    for(i = 1; t[i] != 0; i++) {
        d[i] = isBowel(t[i]);
        sum[i] = sum[i-1]+d[i];
    }
    L = i-1;
    double ANS = sum[L]*L;
    long long t = 0;
    for(i = 2; i <= L; i++) {
        t += sum[i-1]+sum[L]-sum[L-i+1];
        ANS -= t*1.0/i;
    }
    printf("%lf", ANS);
    return 0;
}