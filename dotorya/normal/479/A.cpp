#include <stdio.h>
int max(int a, int b) {
    if(a<b) return b;
    else return a;
}
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int ans = max(a*b*c, a+b+c);
    ans = max(ans, a+b*c);
    ans = max(ans, a*b+c);
    ans = max(ans, (a+b)*c);
    ans = max(ans, a*(b+c));
    printf("%d", ans);
    return 0;
}