#include <stdio.h>
#include <algorithm>
int gcd(int a, int b) {
    if(a>b) std::swap(a, b);
    if(b%a == 0) return a;
    else return gcd(b%a, a);
}
int ans[2000050];
int main() {
    int N, x, y, X, Y, M, i, t;
    scanf("%d %d %d", &N, &x, &y);
    X = x / gcd(x,y);
    Y = y / gcd(x,y);
    M = X+Y;
    long long t1 = 0, t2 = 0;
    for(i = 1; i < M-1; i++) {
        if(t1+X < t2+Y) {
            ans[i] = 0;
            t1 += X;
        }
        else {
            ans[i] = 1;
            t2 += Y;
        }
    }
    ans[0] = ans[M-1] = 2;
    for(i = 1; i <= N; i++) {
        scanf("%lld", &t);
        t2 = ans[t%M];
        if(t2 == 0) printf("Vova\n");
        else if(t2 == 1) printf("Vanya\n");
        else printf("Both\n");
    }
    return 0;
}