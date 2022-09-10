#include<bits/stdc++.h>
int main() {
    int T;
    scanf("%d", &T);
    for(int cs = 1; cs <= T; ++cs) {
        int a, b, x, y;
        scanf("%d%d%d%d", &x, &y, &a, &b);
        int v1 = std::max(a, x - 1 - a) * y;
        int v2 = std::max(b, y - 1 - b) * x;
        printf("%d\n", std::max(v1, v2));
    }
    return 0;
}