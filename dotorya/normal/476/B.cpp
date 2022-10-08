#include <stdio.h>
char s1[15], s2[15];
int abs(int a) {
    if(a>0) return a;
    else return -a;
}
int main() {
    scanf("%s %s", s1, s2);
    int i,t=0, u=0;
    for(i = 0; s1[i] != 0; i++) {
        if(s1[i] == '+') t++;
        if(s1[i] == '-') t--;
    }
    for(i = 0; s2[i] != 0; i++) {
        if(s2[i] == '+') t--;
        if(s2[i] == '-') t++;
        if(s2[i] == '?') u++;
    }
    if(abs(t) > u || (t-u)%2 != 0) {
        printf("0.000000000000");
        return 0;
    }
    double ans = 1;
    int t1 = 1, t2 = 1;
    int a = u, b = (t+u)/2;
    for(i = 1; i <= b; i++) t1 *= i;
    for(i = 1; i <= a-b; i++) t1 *= i;
    for(i = 1; i <= a; i++) t2 *= i;
    ans = (double) t2/t1;
    for(i = 1; i <= a; i++) ans /= 2;
    printf("%.15lf", ans);
    return 0;
}