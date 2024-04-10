#include <stdio.h>
int MIN(int a, int b) {
    if(a<b) return a;
    else return b;
}
int MAX(int a, int b) {
    if(a<b) return b;
    else return a;
}
int main() {
    int H1, A1, D1, H2, A2, D2, h, a, d, i, j, k, t, sum, min=1234567891, base=0;
    scanf("%d %d %d %d %d %d %d %d %d", &H1, &A1, &D1, &H2, &A2, &D2, &h, &a, &d);
    min = MAX(0,(A2-D1))*d+MAX(0, D2-A1+1)*a;
    if(A1 <= D2) {
        base = (D2-A1+1)*a;
        A1 = D2+1;
    }
    for(i = 0; i < A2-D1; i++) {
        for(j = 0; j <= 200; j++) {
            sum = i*d+j*a+base;
            t = (H2+A1+j-D2-1)/(A1+j-D2);
            sum += MAX(0, (A2-D1-i)*t+1-H1)*h;
            if(sum < min) min = sum;
        }
    }
    printf("%d", min);
    return 0;
}