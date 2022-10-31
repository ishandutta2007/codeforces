#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x; scanf("%d%d", &n, &x);
    int cur = 1, ans = 0;
    while(n--) {
        int a, b; scanf("%d%d", &a, &b);
        while(cur + x <= a) cur += x;
        ans += b - cur + 1;
        cur = b + 1;
    }
    printf("%d\n", ans);
    return 0;
}