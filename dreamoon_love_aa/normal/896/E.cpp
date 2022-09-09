#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<cstdio>
const int SIZE = 100'001;
int a[SIZE];
void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    while(m--){
        int ty, l, r, x;
        scanf("%d%d%d%d", &ty, &l, &r, &x);
        if(ty == 1) {
            for(int i = l; i <= r; i++) {
                if(a[i] > x) a[i] -= x;
            }
        } else {
            int an = 0;
            for(int i = l; i <= r; i++) {
                an += (a[i] == x);
            }
            printf("%d\n", an);
        }
    }
}
int main() {
    solve();
    return 0;
}