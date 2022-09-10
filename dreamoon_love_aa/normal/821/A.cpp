#include<bits/stdc++.h>
void solve() {
    int n;
    scanf("%d", &n);
    int a[51][51];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) {
            scanf("%d", &a[i][j]);
        }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j) {
            if(a[i][j] == 1) continue;
            bool suc = false;
            for(int k = 1; k <= n; k++)
                for(int r = 1; r <= n; r++) {
                    if(a[i][k] + a[r][j] == a[i][j]) suc = true;
                }
            if(!suc) {
                puts("No");
                return;
            }
        }
    puts("Yes");
}
int main() {
    solve();
    return 0;
}