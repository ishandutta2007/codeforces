#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
long long C(int x, int y) {
    long long res = 1;
    for(int i = 1; i <= y; i++) {
        res *= x - y + i;
        res /= i;
    }
    return res;
}
long long fac(int n) {
    if(n <= 1) {
        return 1;
    }
    return fac(n - 1) * n;
}
int main() {
    int n;
    scanf("%d", &n);
    if(n == 2) {
        puts("1");
    } else if(n == 4) {
        puts("3");
    } else {
        int k = n / 2;
        long long ans = C(n - 1, n / 2 - 1) * fac(k) / k * fac(k) /  k;
        printf("%lld\n", ans);
    }
    return 0;
}