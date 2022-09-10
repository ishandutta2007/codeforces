#include<bits/stdc++.h>
const int SIZE = 1000;
int a[SIZE];
int b[SIZE];
void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
    }
    for(int i = 0; i < n; ++i) {
        if(a[i] != b[i]) {
            puts("rated");
            return;
        }
    }
    for(int i = 1; i < n; ++i) {
        if(a[i] > a[i - 1]) {
            puts("unrated");
            return;
        }
    }
    puts("maybe");
}
int main() {
    solve();
    return 0;
}