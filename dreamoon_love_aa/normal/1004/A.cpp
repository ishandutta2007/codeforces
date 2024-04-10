#include<bits/stdc++.h>
void solve() {
    int n, d;
    scanf("%d%d", &n, &d);
    int x[100];
    for(int i = 0; i < n; ++i) scanf("%d", &x[i]);
    std::sort(x, x + n);
    int an = 2;
    for(int i = 1; i < n; ++i) {
        if(x[i] - x[i - 1] == 2 * d) an++;
        else if(x[i] - x[i - 1] > 2 * d) an += 2;
    }
    printf("%d\n", an);
}
int main() {
    solve();
    return 0;
}