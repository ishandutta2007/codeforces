#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
void solve() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", n);
        for(int i = 1; i <= n; i++) {
            printf("%d%c", i, " \n"[i == n]);
        }
    }
}
int main() {
    solve();
    return 0;
}