#include <stdio.h>
#include <math.h>
int main() {
    int R, X1, Y1, X2, Y2, i;
    scanf("%d %d %d %d %d", &R, &X1, &Y1, &X2, &Y2);
    double L = pow(1.0*(X1-X2)*(X1-X2)+1.0*(Y1-Y2)*(Y1-Y2), 0.5);
    R *= 2;
    for(i = 0;;i++) {
        if(R*i - L >= -0.0000001) break;
    }
    printf("%d", i);
    return 0;
}