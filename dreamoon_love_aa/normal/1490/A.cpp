#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
int a[55];
int f(int x, int y) {
    if(x > y) {
        swap(x, y);
    }
    int ret = 0;
    while(x * 2 < y) {
        x *= 2;
        ret++;
    }
    return ret;
}
void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int an = 0;
    for(int i = 1; i < n; i++) {
        an += f(a[i-1], a[i]);
    }
    printf("%d\n", an);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}