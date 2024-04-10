#include<bits/stdc++.h>
const int SIZE = 101;
int b[SIZE], d[SIZE], an[SIZE * 2];;
bool u[SIZE * 2];
void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        d[i] = b[i];
        u[i * 2] = u[i * 2 - 1] = 0;
    }
    std::sort(d + 1, d + 1 + n);
    for(int i = 1; i <= n; i++) {
        u[b[i]] = 1;
        if(d[i] >= 2 * i) {
            puts("-1");
            return;
        }
    }
    for(int i = 1; i <= n; i++) {
        an[i * 2 - 1] = b[i];
        for(int j = b[i] + 1; ; j++) {
            if(!u[j]) {
                an[i * 2] = j;
                u[j] = 1;
                break;
            }
        }
    }
    for(int i = 1; i <= 2 * n; i++) {
        printf("%d", an[i]);
        if(i < 2 * n) printf(" ");
        else puts("");
    }
}
int main() {
    int T;
    scanf("%d", &T);
    for(int cs = 1; cs <= T; ++cs) {
        solve();
    }
    return 0;
}