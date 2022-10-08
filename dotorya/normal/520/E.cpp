#include <stdio.h>
char A[100050];
long long pow_10[100050];
long long factorial[100050];
long long rev_factorial[100050];
int chk[35];
int a[100050];
int sum_a[100050];
long long calculateReverseFactorial(long long x) {
    long long tmp = x, ans = 1;
    for(int i = 0; i <= 34; i++) {
        if(chk[i] == 1) ans = (ans*tmp)%1000000007;
        tmp = (tmp*tmp)%1000000007;
    }
    return ans;
}
int main() {
    int N, K, i;
    long long ans = 0, tmp;
    scanf("%d %d %s", &N, &K, &A[1]);
    for(i = 1; i <= N; i++) {
        a[i] = A[i]-'0';
        sum_a[i] = sum_a[i-1]+a[i];
    }
    pow_10[0] = 1;
    for(i = 1; i <= N-K+1; i++) pow_10[i] = (pow_10[i-1]*10)%1000000007;
    if(K == 0) {
        for(i = 1; i <= N; i++) {
            ans += a[i] * pow_10[N-i];
            ans = ans % 1000000007;
        }
        printf("%lld", ans);
        return 0;
    }
    factorial[0] = 1;
    for(i = 1; i <= N-2; i++) factorial[i] = (factorial[i-1] * i) % 1000000007;
    int t = 1000000005;
    for(i = 0; t != 0; i++) {
        chk[i] = t%2;
        t /= 2;
    }
    rev_factorial[0] = 1;
    for(i = 1; i <= N-2; i++) rev_factorial[i] = calculateReverseFactorial(factorial[i]);
    for(i = 0; i <= N-1-K; i++) {
        tmp = sum_a[N-i];
        tmp = (tmp*pow_10[i])%1000000007;
        tmp = (tmp*factorial[N-2-i])%1000000007;
        tmp = (tmp*rev_factorial[K-1])%1000000007;
        tmp = (tmp*rev_factorial[N-K-i-1])%1000000007;
        ans = (ans+tmp)%1000000007;
    }
    for(i = 0; i <= N-K-2; i++) {
        tmp = a[N-i];
        tmp = (tmp*pow_10[i])%1000000007;
        tmp = (tmp*factorial[N-2-i])%1000000007;
        tmp = (tmp*rev_factorial[K])%1000000007;
        tmp = (tmp*rev_factorial[N-K-i-2])%1000000007;
        ans = (ans+tmp)%1000000007;
    }
    printf("%lld", ans);
    return 0;
}