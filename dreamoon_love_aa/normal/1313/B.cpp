#include<bits/stdc++.h>
void solve() {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    if(x > y) std::swap(x, y);
    int an1, an2;
    if(x + y <= n) {
        an1 = 1;
        an2 = x + y - 1;
    }
    else {
        an1 = n - std::max(0, (n - (x + y - n + 1)));
        an2 = n;
    }
    printf("%d %d\n", an1, an2);
}
int main() {
    int T;
    scanf("%d", &T);
    for(int cs = 1; cs <= T; cs++) solve();
    return 0;
}