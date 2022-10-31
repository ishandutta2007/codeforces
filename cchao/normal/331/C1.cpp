#include <cstdio>
#include <iostream>
using namespace std;
int digit(int x) {
    int ret = 0;
    while(x) {
        ret = max(ret, x % 10);
        x /= 10;
    }
    return ret;
}

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    while(n) {
        n -= digit(n);
        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}