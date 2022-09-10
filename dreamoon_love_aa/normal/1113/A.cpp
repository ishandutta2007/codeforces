#include<bits/stdc++.h>
void solve() {
    int n, v;
    scanf("%d%d", &n, &v);
    int an = std::min(n - 1, v);
    for(int i = 2; i + v <= n; ++i) an += i;
    printf("%d\n", an);
}
int main() {
    solve();
    return 0;
}