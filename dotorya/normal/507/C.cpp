#include <stdio.h>
long long pow_2[62];
int bin[62];
void get_pow2() {
    int i;
    pow_2[0] = 1;
    for(i = 1; i <= 60; i++) pow_2[i] = pow_2[i-1] * 2;
}
int main() {
    int i, j, H;
    long long N;
    get_pow2();
    scanf("%d %lld", &H, &N);
    N--;
    for(i = H; i >= 1; i--) {
        bin[i] = N%2;
        N /= 2;
    }
    bin[0] = 1;
    long long ANS = pow_2[H+1]-2;
    for(i = 0; i < H; i++) {
        if(bin[i] != bin[i+1]) ANS -= pow_2[H-i]-1;
    }
    printf("%lld", ANS);
    return 0;
}