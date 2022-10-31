#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, a, b, v;
    scanf("%d%d%d%d", &k, &a, &b, &v);
    int n = (a + v - 1) / v;
    int ans = 0;
    // printf("n = %d\n", n);
    while(n > 0) {
        int t = min(b, k - 1);
        // printf("t = %d\n", t);
        ans++;
        n -= t + 1;
        b -= t;
    }
    printf("%d\n", ans);
    return 0;
}