#include<bits/stdc++.h>
int solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    int a[101], b[102] = {};
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= m; i++) {
        int x;
        scanf("%d", &x);
        b[x] = 1;
    }
    for(int i = 1, j; i <= n; i = j) {
        for(j = i; j <= n && b[j]; j++);
        if(j == i) {
            j = i + 1;
        }
        else {
            std::sort(a + i, a + j + 1);
        }
    }
    for(int i = 2; i <= n; i++) {
        if(a[i] < a[i - 1]) return 0;
    }
    return 1;
}
int main() {
    int T;
    scanf("%d", &T);
    for(int cs = 1; cs <= T; cs++) {
        puts(solve() ? "YES" : "NO");
    }
    return 0;
}