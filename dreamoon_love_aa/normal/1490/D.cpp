#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
int a[111], an[111];
void f(int l, int r, int lv) {
    if(l > r) { return; }
    int ma_pos = max_element(a + l, a + r + 1) - a;
    an[ma_pos] = lv;
    f(l, ma_pos - 1, lv + 1);
    f(ma_pos + 1, r, lv + 1);
}
void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    f(1, n, 0);
    for(int i = 1; i <= n; i++) {
        if(i > 1) printf(" ");
        printf("%d", an[i]);
    }
    puts("");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}