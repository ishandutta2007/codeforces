#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("%d",4 * n - i * 2);
        if(i < n - 1) {
            printf(" ");
        } else {
            puts("");
        }
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}