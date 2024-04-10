#include <stdio.h>
int d[20];
int pow_2[20] = {1,2,4,8,16,32,64,128,256,512,1024};
int main() {
    int N, i;
    scanf("%d", &N);
    for(i = 1; N != 0; i++) {
        d[i] = N%10;
        if(d[i] == 4) d[i] = 1;
        else d[i] = 2;
        N /= 10;
    }
    int L = i-1, ans = 0;
    for(i = 1; i < L; i++) ans += pow_2[i];
    for(i = 1; i <= L; i++) ans += (d[i]-1)*pow_2[i-1];
    printf("%d",ans+1);
    return 0;
}